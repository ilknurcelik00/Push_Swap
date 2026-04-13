#include "push_swap.h"

/*
** swap_top: stack'in ilk iki node'unu yer değiştirir
** Mantık: pointer'ları değiştirmek yerine sadece VALUE'ları takas et
** Bu çok daha temiz ve hatasız
*/
static void swap_top(t_stack *stack)
{
    int tmp;

    if (!stack || !stack->next)
        return ;
    tmp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = tmp;
    /* index'leri de takas etmeyi unutma! */
    tmp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = tmp;
}

void    sa(t_stack **a)
{
    swap_top(*a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    swap_top(*b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    swap_top(*a);
    swap_top(*b);
    write(1, "ss\n", 3);
}