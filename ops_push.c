#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (!*src)
		return ;
	node = pop_front(src);
	push_front(dst, node);
}

void	pa(t_stack **a, t_stack **b, t_config *cfg)
{
	push(a, b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_pa++;
		if (!cfg->count_only)
			write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b, t_config *cfg)
{
	push(b, a);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_pb++;
		if (!cfg->count_only)
			write(1, "pb\n", 3);
	}
}
