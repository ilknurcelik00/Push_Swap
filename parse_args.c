#include "push_swap.h"

void    error_exit(t_stack **a, t_stack **b)
{
    if (a && *a)
        free_stack(a);
    if (b && *b)
        free_stack(b);
    ft_putstr_fd("Error\n", 2);
    exit(1);
}

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

static int  is_mode_flag(char *arg)
{
    if (ft_strncmp(arg, "--bench", 8) == 0)
        return (1);
    if (ft_strncmp(arg, "--count-only", 13) == 0)
        return (1);
    return (0);
}

/*
** parse_token: tek bir token'ı işle (boşlukla ayrılmış sayı)
** token boşluk içeriyorsa alt token'lara böl, her birini stack'e ekle
*/
static void parse_token(char *token, t_stack **a)
{
    int     i;
    int     start;
    char    tmp[32];
    int     val;
    int     k;

    i = 0;
    while (token[i])
    {
        while (token[i] == ' ' || token[i] == '\t')
            i++;
        if (!token[i])
            break ;
        start = i;
        if (token[i] == '-' || token[i] == '+')
            i++;
        if (!token[i] || token[i] < '0' || token[i] > '9')
            error_exit(a, NULL);
        while (token[i] >= '0' && token[i] <= '9')
            i++;
        if (token[i] != '\0' && token[i] != ' ' && token[i] != '\t')
            error_exit(a, NULL);
        k = 0;
        while (start < i)
            tmp[k++] = token[start++];
        tmp[k] = '\0';
        ft_parse_int(tmp, &val, a);
        if (is_duplicate(*a, val))
            error_exit(a, NULL);
        push_front(a, new_node(val));
    }
}

void    parse_args(int argc, char **argv, t_stack **a,
                    char **strategy, int *count_only, int *bench_mode)
{
    int     i;

    if (argc == 1)
        exit(0);
    *strategy = "--adaptive";
    *count_only = 0;
    *bench_mode = 0;
    i = 1;
    while (i < argc && (parse_strategy(argv[i]) || is_mode_flag(argv[i])))
    {
        if (parse_strategy(argv[i]))
            *strategy = parse_strategy(argv[i]);
        else if (ft_strncmp(argv[i], "--bench", 8) == 0)
            *bench_mode = 1;
        else if (ft_strncmp(argv[i], "--count-only", 13) == 0)
            *count_only = 1;
        i++;
    }
    if (i >= argc)
        exit(0);
    while (i < argc)
    {
        parse_token(argv[i], a);
        i++;
    }
    reverse_stack(a);
}