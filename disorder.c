#include "push_swap.h"

/*
** stack_to_array: linked list'i geçici int dizisine çevir
** compute_disorder içinde kullanmak için
** Çağıran free etmekle sorumlu!
*/
static int  *stack_to_array(t_stack *stack, int size)
{
    int *arr;
    int i;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    i = 0;
    while (stack)
    {
        arr[i++] = stack->value;
        stack = stack->next;
    }
    return (arr);
}

/*
** compute_disorder: stack'in ne kadar karışık olduğunu ölç
**
** Döndürür:
**   0.0 → tamamen sıralı
**   1.0 → tamamen ters sıralı
**
** Özel durumlar:
**   0 veya 1 elemanlı stack → zaten sıralı → 0.0 döndür
**   malloc başarısız        → güvenli taraf → 1.0 döndür
**                             (en agresif algoritmayı seç)
*/
double  compute_disorder(t_stack *a)
{
    int     *arr;
    int     size;
    int     i;
    int     j;
    long    mistakes;
    long    total_pairs;

    size = stack_size(a);
    if (size <= 1)
        return (0.0);
    arr = stack_to_array(a, size);
    if (!arr)
        return (1.0);
    mistakes = 0;
    total_pairs = 0;
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            total_pairs++;
            if (arr[i] > arr[j])
                mistakes++;
            j++;
        }
        i++;
    }
    free(arr);
    return ((double)mistakes / (double)total_pairs);
}