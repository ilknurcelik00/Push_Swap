#include "push_swap.h"

/*
** print_bench: benchmark raporunu stderr'e yaz
** Disorder %, strateji adı, toplam op sayısı,
** her operasyon türünün sayısı
*/
void    print_bench(char *strategy, double disorder)
{
    char    *strat_name;
    char    *complexity;

    if (ft_strncmp(strategy, "--simple", 9) == 0)
    {
        strat_name = "Simple";
        complexity = "O(n^2)";
    }
    else if (ft_strncmp(strategy, "--medium", 9) == 0)
    {
        strat_name = "Medium";
        complexity = "O(n*sqrt(n))";
    }
    else if (ft_strncmp(strategy, "--complex", 10) == 0)
    {
        strat_name = "Complex";
        complexity = "O(n log n)";
    }
    else
    {
        strat_name = "Adaptive";
        complexity = "O(adaptive)";
    }
    ft_putstr_fd("=== push_swap benchmark ===\n", 2);
    ft_putstr_fd("Disorder: ", 2);
    ft_putnbr_fd((int)(disorder * 10000) / 100, 2);
    ft_putchar_fd('.', 2);
    ft_putnbr_fd((int)(disorder * 10000) % 100, 2);
    ft_putstr_fd("%\n", 2);
    ft_putstr_fd("Strategy: ", 2);
    ft_putstr_fd(strat_name, 2);
    ft_putstr_fd(" (", 2);
    ft_putstr_fd(complexity, 2);
    ft_putstr_fd(")\n", 2);
    ft_putstr_fd("Total operations: ", 2);
    ft_putnbr_fd(g_op_count, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("  sa:", 2);
    ft_putnbr_fd(g_cnt_sa, 2);
    ft_putstr_fd(" sb:", 2);
    ft_putnbr_fd(g_cnt_sb, 2);
    ft_putstr_fd(" ss:", 2);
    ft_putnbr_fd(g_cnt_ss, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("  pa:", 2);
    ft_putnbr_fd(g_cnt_pa, 2);
    ft_putstr_fd(" pb:", 2);
    ft_putnbr_fd(g_cnt_pb, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("  ra:", 2);
    ft_putnbr_fd(g_cnt_ra, 2);
    ft_putstr_fd(" rb:", 2);
    ft_putnbr_fd(g_cnt_rb, 2);
    ft_putstr_fd(" rr:", 2);
    ft_putnbr_fd(g_cnt_rr, 2);
    ft_putchar_fd('\n', 2);
    ft_putstr_fd("  rra:", 2);
    ft_putnbr_fd(g_cnt_rra, 2);
    ft_putstr_fd(" rrb:", 2);
    ft_putnbr_fd(g_cnt_rrb, 2);
    ft_putstr_fd(" rrr:", 2);
    ft_putnbr_fd(g_cnt_rrr, 2);
    ft_putchar_fd('\n', 2);
}
