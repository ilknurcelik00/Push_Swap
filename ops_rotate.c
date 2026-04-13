#include "push_swap.h"

/*
** rotate: tepeyi sona taşı
** 1. pop_front ile tepeden söküp al
** 2. stack_last ile sona git, oraya bağla
*/
static void rotate(t_stack **stack)
{
    t_stack *node;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return ;
    node = pop_front(stack);   /* tepeden söküp al */
    last = stack_last(*stack); /* son node'u bul */
    last->next = node;         /* node'u sona bağla */
    node->prev = last;
    node->next = NULL;
}

/*
** rev_rotate: sonu tepeye taşı
** 1. son node'u bul
** 2. onu listeden söküp al
** 3. push_front ile tepeye ekle
*/
static void rev_rotate(t_stack **stack)
{
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return ;
    last = stack_last(*stack);
    /* son node'u listeden kopar */
    last->prev->next = NULL;
    last->prev = NULL;
    /* tepeye ekle */
    push_front(stack, last);
}

void    ra(t_stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void    rra(t_stack **a)
{
    rev_rotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack **b)
{
    rev_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
    write(1, "rrr\n", 4);
}