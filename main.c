#include "push_swap.h"

/* Global sayaçlar */
int g_op_count = 0;
int g_count_only = 0;
int g_cnt_sa = 0;
int g_cnt_sb = 0;
int g_cnt_ss = 0;
int g_cnt_pa = 0;
int g_cnt_pb = 0;
int g_cnt_ra = 0;
int g_cnt_rb = 0;
int g_cnt_rr = 0;
int g_cnt_rra = 0;
int g_cnt_rrb = 0;
int g_cnt_rrr = 0;

static void run_sort(t_stack **a, t_stack **b, char *strategy)
{
    if (ft_strncmp(strategy, "--simple", 9) == 0)
        sort_simple(a, b);
    else if (ft_strncmp(strategy, "--medium", 9) == 0)
        sort_medium(a, b);
    else if (ft_strncmp(strategy, "--complex", 10) == 0)
        sort_complex(a, b);
    else
        sort_adaptive(a, b);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    char    *strategy;
    int     count_only;
    int     bench_mode;
    double  disorder;

    a = NULL;
    b = NULL;
    strategy = "--adaptive";
    count_only = 0;
    bench_mode = 0;
    parse_args(argc, argv, &a, &strategy, &count_only, &bench_mode);
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }
    disorder = compute_disorder(a);
    g_count_only = count_only;
    run_sort(&a, &b, strategy);
    if (count_only)
    {
        ft_putnbr_fd(g_op_count, 1);
        write(1, "\n", 1);
    }
    if (bench_mode)
        print_bench(strategy, disorder);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
