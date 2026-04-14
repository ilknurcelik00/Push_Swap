#include "push_swap.h"

/* Yeni node oluştur */
t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/* Stack'in ÖNÜNE (tepesine) node ekle */
void	push_front(t_stack **stack, t_stack *node)
{
	if (!node)
		return ;
	node->next = *stack; /* yeni node'un next'i eski tepe */
	node->prev = NULL;   /* yeni tepenin prev'i yok */
	if (*stack)
		(*stack)->prev = node; /* eski tepenin prev'i yeni node */
	*stack = node;             /* pointer'ı yeni tepeye güncelle */
}

/* Stack'in ÖNÜNDEN (tepesinden) node çıkar ve döndür */
t_stack	*pop_front(t_stack **stack)
{
	t_stack	*node;

	if (!*stack)
		return (NULL);
	node = *stack;
	*stack = node->next; /* pointer bir sonrakine kayar */
	if (*stack)
		(*stack)->prev = NULL; /* yeni tepenin prev'i NULL olur */
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/* Stack'teki eleman sayısını döndür */
int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

/* Stack'in son node'unu döndür */
t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/* Stack'i tamamen serbest bırak */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
void	reverse_stack(t_stack **stack)
{
	t_stack	*cur;
	int		*arr;
	int		size;
	int		i;

	size = stack_size(*stack);
	if (size <= 1)
		return ;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	cur = *stack;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	cur = *stack;
	i = size - 1;
	while (cur)
	{
		cur->value = arr[i--];
		cur = cur->next;
	}
	free(arr);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	normalize_stack(t_stack *stack)
{
	t_stack *cur;
	t_stack *cmp;
	int rank;

	cur = stack;
	while (cur)
	{
		rank = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < cur->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}