#include "push_swap.h"

static void	swap_top(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	sa(t_stack **a, t_config *cfg)
{
	swap_top(*a);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_sa++;
		if (!cfg->count_only)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b, t_config *cfg)
{
	swap_top(*b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_sb++;
		if (!cfg->count_only)
			write(1, "sb\n", 3);
	}
}

void	ss(t_stack **a, t_stack **b, t_config *cfg)
{
	swap_top(*a);
	swap_top(*b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_ss++;
		if (!cfg->count_only)
			write(1, "ss\n", 3);
	}
}
