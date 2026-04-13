#include "push_swap.h"

static void swap_top(t_stack *stack)
{
    int tmp;

    if (!stack || !stack->next)
        return ;
    tmp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = tmp;
    tmp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = tmp;
}

void    sa(t_stack **a)
{
    swap_top(*a);
    g_op_count++;
    g_cnt_sa++;
    if (!g_count_only)
        write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    swap_top(*b);
    g_op_count++;
    g_cnt_sb++;
    if (!g_count_only)
        write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    swap_top(*a);
    swap_top(*b);
    g_op_count++;
    g_cnt_ss++;
    if (!g_count_only)
        write(1, "ss\n", 3);
}
