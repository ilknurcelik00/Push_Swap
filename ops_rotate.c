#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	node = pop_front(stack);
	last = stack_last(*stack);
	last->next = node;
	node->prev = last;
	node->next = NULL;
}

void	ra(t_stack **a, t_config *cfg)
{
	rotate(a);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_ra++;
		if (!cfg->count_only)
			write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b, t_config *cfg)
{
	rotate(b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rb++;
		if (!cfg->count_only)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b, t_config *cfg)
{
	rotate(a);
	rotate(b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rr++;
		if (!cfg->count_only)
			write(1, "rr\n", 3);
	}
}
