#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (!*src)
		return ;
	node = pop_front(src);
	push_front(dst, node);
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	g_op_count++;
	g_cnt_pa++;
	if (!g_count_only)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	g_op_count++;
	g_cnt_pb++;
	if (!g_count_only)
		write(1, "pb\n", 3);
}
