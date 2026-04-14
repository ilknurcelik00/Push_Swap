#include "push_swap.h"
static int  find_min_pos(t_stack *stack)
{
    int     pos;
    int     min_pos;
    int     min_val;

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
static void bring_to_top(t_stack **a, int pos, int size)
{
    if (pos <= size / 2)
    {
        while (pos-- > 0)
            ra(a);
    }
    else
    {
        pos = size - pos;
        while (pos-- > 0)
            rra(a);
    }
}
void    sort_simple(t_stack **a, t_stack **b)
{
    int size;
    int min_pos;

    size = stack_size(*a);
    while (size > 1)
    {
        min_pos = find_min_pos(*a);
        bring_to_top(a, min_pos, size);
        pb(a, b);
        size--;
    }
    while (*b)
        pa(a, b);
}