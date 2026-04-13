#include "push_swap.h"

/*
** push: src'nin tepesini çıkar, dst'nin tepesine ekle
** pop_front ve push_front zaten stack_utils.c'de tanımlı
*/
static void push(t_stack **dst, t_stack **src)
{
    t_stack *node;

    if (!*src)
        return ;
    node = pop_front(src);   /* src'nin tepesini söküp al */
    push_front(dst, node);   /* dst'nin tepesine yerleştir */
}

void    pa(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}