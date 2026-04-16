#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	int	pos;
	int	min_pos;
	int	min_val;

	pos = 0;
	min_pos = 0;
	min_val = stack->value;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

int	find_max_pos(t_stack *stack)
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
