#include "push_swap.h"

/*
** sort_adaptive: disorder'a göre en uygun algoritmayı seç
**
** disorder = 0.0 → tamamen sıralı
** disorder = 1.0 → tamamen ters sıralı
**
** Eşik değerleri:
**   < 0.2  → neredeyse sıralı → simple yeterli
**   < 0.5  → orta karışık    → medium (chunk sort)
**   >= 0.5 → çok karışık     → complex (radix sort)
*/
void    sort_adaptive(t_stack **a, t_stack **b)
{
    double  disorder;

    disorder = compute_disorder(*a);
    if (disorder < 0.2)
        sort_simple(a, b);
    else if (disorder < 0.5)
        sort_medium(a, b);
    else
        sort_complex(a, b);
}