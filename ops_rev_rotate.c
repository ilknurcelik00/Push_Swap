#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	push_front(stack, last);
}

void	rra(t_stack **a, t_config *cfg)
{
	rev_rotate(a);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rra++;
		if (!cfg->count_only)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b, t_config *cfg)
{
	rev_rotate(b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rrb++;
		if (!cfg->count_only)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b, t_config *cfg)
{
	rev_rotate(a);
	rev_rotate(b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rrr++;
		if (!cfg->count_only)
			write(1, "rrr\n", 4);
	}
}
