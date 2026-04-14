#include "push_swap.h"

/* math.h YOK — kendi sqrt'ımızı kullanıyoruz */
static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	chunk_count(int n)
{
	int	chunks;

	chunks = ft_sqrt(n);
	if (chunks < 1)
		chunks = 1;
	return (chunks);
}

/*
** in_chunk: bu index hangi chunk'a ait?
** chunk_size = n / chunks
** index / chunk_size bize chunk numarasını verir
*/
static int	in_chunk(int index, int target_chunk, int chunk_size)
{
	return (index / chunk_size == target_chunk);
}

/*
** find_max_pos: b'deki en büyük elemanın tepeden kaç adım uzakta
** olduğunu döndür — rb mi rrb mi kararını vermek için
*/
static int	find_max_pos(t_stack *stack)
{
	int	pos;
	int	max_pos;
	int	max_val;

	pos = 0;
	max_pos = 0;
	max_val = stack->index;
	while (stack)
	{
		if (stack->index > max_val)
		{
			max_val = stack->index;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

/*
** bring_max_to_top: b'deki max'ı tepeye getir
** max tepeden yakınsa rb, alttan yakınsa rrb kullan
** bu operasyon sayısını minimize eder
*/
static void	bring_max_to_top(t_stack **b, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

/*
** phase1: a'dan b'ye chunk chunk gönder
** her chunk için: tüm a'yı tara, bu chunk'a ait olanları pb
** ait olmayanları ra ile geç
*/
static void	phase1(t_stack **a, t_stack **b, int chunks, int chunk_size)
{
	int	target;
	int	pushed;
	int	size;
	int	rotated;

	target = 0;
	while (target < chunks)
	{
		pushed = 0;
		size = stack_size(*a);
		rotated = 0;
		while (pushed < chunk_size && rotated < size)
		{
			if (in_chunk((*a)->index, target, chunk_size))
			{
				pb(a, b);
				pushed++;
				size--;
				rotated = 0;
			}
			else
			{
				ra(a);
				rotated++;
			}
		}
		target++;
	}
	/* kalan elemanları da b'ye at */
	while (*a)
		pb(a, b);
}

/*
** phase2: b'den a'ya max'ı çekerek geri al
** her seferinde b'deki en büyük index'li elemanı tepeye getir
** pa ile a'ya ekle → a küçükten büyüğe dolacak
*/
static void	phase2(t_stack **a, t_stack **b)
{
	int	size;
	int	max_pos;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = find_max_pos(*b);
		bring_max_to_top(b, max_pos, size);
		pa(a, b);
	}
}

/*
** sort_medium: O(n√n) chunk sort
** 1. normalize: value → index (0..n-1)
** 2. chunk_count hesapla
** 3. phase1: chunk chunk b'ye gönder
** 4. phase2: b'den max'ı çekerek a'ya sıralı geri al
*/
void	sort_medium(t_stack **a, t_stack **b)
{
	int n;
	int chunks;
	int chunk_size;

	n = stack_size(*a);
	normalize_stack(*a);
	chunks = chunk_count(n);
	chunk_size = n / chunks;
	phase1(a, b, chunks, chunk_size);
	phase2(a, b);
}