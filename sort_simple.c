#include "push_swap.h"

static void	sort_three(t_stack **a, t_config *cfg)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a, cfg);
	else if (x > y && y > z)
	{
		sa(a, cfg);
		rra(a, cfg);
	}
	else if (x > y && y < z && x > z)
		ra(a, cfg);
	else if (x < y && y > z && x < z)
	{
		sa(a, cfg);
		ra(a, cfg);
	}
	else
		rra(a, cfg);
}

static void	bring_to_top(t_stack **a, int pos, int size, t_config *cfg)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, cfg);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a, cfg);
	}
}

void	sort_simple(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	if (size == 3)
	{
		sort_three(a, cfg);
		return ;
	}
	while (size > 1)
	{
		min_pos = find_min_pos(*a);
		bring_to_top(a, min_pos, size, cfg);
		pb(a, b, cfg);
		size--;
	}
	while (*b)
		pa(a, b, cfg);
}
