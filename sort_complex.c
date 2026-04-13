#include "push_swap.h"

/*
** bit_length: n sayısını temsil etmek için kaç bit lazım?
** 1<<bits, n'i ilk geçtiği anda dur
*/
static int  bit_length(int n)
{
    int bits;

    bits = 0;
    while ((1 << bits) < n)
        bits++;
    return (bits);
}

/*
** sort_complex: O(n log n) radix sort (LSD)
**
** Her bit turu:
**   bit=0 → pb   (b'ye gönder)
**   bit=1 → ra   (a'da bırak, sona at)
** Tur bitti → b'deki hepsini pa ile geri al
** bit_length(n) tur sonunda a sıralı
*/
void    sort_complex(t_stack **a, t_stack **b)
{
    int n;
    int bits;
    int bit;
    int i;
    int size;

    n = stack_size(*a);
    normalize_stack(*a);
    bits = bit_length(n);
    bit = 0;
    while (bit < bits)
    {
        size = stack_size(*a);
        i = 0;
        while (i < size)
        {
            if (((*a)->index >> bit) & 1)
                ra(a);
            else
                pb(a, b);
            i++;
        }
        while (*b)
            pa(a, b);
        bit++;
    }
}