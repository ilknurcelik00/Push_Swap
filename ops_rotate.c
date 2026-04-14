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

void	ra(t_stack **a)
{
	rotate(a);
	g_op_count++;
	g_cnt_ra++;
	if (!g_count_only)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	g_op_count++;
	g_cnt_rb++;
	if (!g_count_only)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	g_op_count++;
	g_cnt_rr++;
	if (!g_count_only)
		write(1, "rr\n", 3);
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	g_op_count++;
	g_cnt_rra++;
	if (!g_count_only)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	g_op_count++;
	g_cnt_rrb++;
	if (!g_count_only)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	g_op_count++;
	g_cnt_rrr++;
	if (!g_count_only)
		write(1, "rrr\n", 4);
}
