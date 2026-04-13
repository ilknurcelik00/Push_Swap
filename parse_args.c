#include "push_swap.h"

/*
** error_exit: "Error\n" yaz, her iki stack'i temizle, çık
** ft_putstr_fd(s, 2) → fd=2 yani stderr'e yazar
** Her hata durumunda buraya geliyoruz
*/
void    error_exit(t_stack **a, t_stack **b)
{
    if (a && *a)
        free_stack(a);
    if (b && *b)
        free_stack(b);
    ft_putstr_fd("Error\n", 2);
    exit(1);
}

/*
** is_duplicate: val değeri zaten stack'te var mı?
** Döngüyle tüm node'ları gez, value'yu karşılaştır
*/
static int  is_duplicate(t_stack *a, int val)
{
    while (a)
    {
        if (a->value == val)
            return (1);
        a = a->next;
    }
    return (0);
}

/*
** parse_strategy: ilk argüman bir flag mi?
** "--simple", "--medium", "--complex", "--adaptive" kontrolü
** Eşleşirse ilgili strateji string'ini döndür, değilse NULL
*/
static char *parse_strategy(char *arg)
{
    if (ft_strncmp(arg, "--simple", 9) == 0)
        return ("--simple");
    if (ft_strncmp(arg, "--medium", 9) == 0)
        return ("--medium");
    if (ft_strncmp(arg, "--complex", 10) == 0)
        return ("--complex");
    if (ft_strncmp(arg, "--adaptive", 11) == 0)
        return ("--adaptive");
    return (NULL);
}

/*
** parse_args: tüm argümanları oku, validate et, stack a'yı doldur
**
** strategy: dışarıdan pointer olarak alıyoruz, buradan set ediyoruz
**           main.c'de "char *strategy" olarak tutulacak
**
** Akış:
**   1. argc == 1 ise hiç argüman yok → çık (hata değil, normal)
**   2. argv[1] flag mi? → strategy'yi ayarla, start=2
**   3. argv[start..argc-1] arası her argüman için:
**      a. valid int string mi?
**      b. INT aralığında mı?
**      c. duplicate var mı?
**      d. hepsi geçtiyse stack'e ekle
**   4. stack ters sırada doluyor (push_front) → sonunda reverse et
*/
void    parse_args(int argc, char **argv,
                    t_stack **a, char **strategy)
{
    int     i;
    int     start;
    int    val;

    if (argc == 1)
        exit(0);
    *strategy = "--adaptive";
    start = 1;
    if (parse_strategy(argv[1]))
    {
        *strategy = parse_strategy(argv[1]);
        start = 2;
    }
    if (start >= argc)
        exit(0);
    i = start;
    while (i < argc)
    {
        ft_parse_int(argv[i], &val, a);
        push_front(a, new_node(val));
        i++;
    }
    reverse_stack(a);
}