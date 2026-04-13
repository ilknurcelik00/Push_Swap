#include "push_swap.h"

/*
** find_min_pos: stack'teki en küçük value'nun
** tepeden kaç adım uzakta olduğunu döndür
** (tepe = 0, bir sonraki = 1, ...)
*/
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

/*
** bring_to_top: min_pos adım uzaktaki elemanı tepeye getir
** ra ile döndür (her ra bir adım yukarı taşır)
*/
static void bring_to_top(t_stack **a, int pos)
{
    while (pos > 0)
    {
        ra(a);
        pos--;
    }
}

/*
** sort_simple: O(n²) selection sort
**
** Her turda:
**   1. en küçüğü bul (find_min_pos)
**   2. tepeye getir (bring_to_top → ra)
**   3. b'ye gönder (pb)
** Sonunda b'dekini a'ya geri al (pa)
*/
void    sort_simple(t_stack **a, t_stack **b)
{
    int size;
    int min_pos;

    size = stack_size(*a);
    while (size > 1)
    {
        min_pos = find_min_pos(*a);
        bring_to_top(a, min_pos);
        pb(a, b);
        size--;
    }
    while (*b)
        pa(a, b);
}