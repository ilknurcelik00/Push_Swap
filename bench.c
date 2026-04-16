#include "push_swap.h"

static void	get_strat_name(char *strategy, char **name, char **comp)
{
	if (ft_strncmp(strategy, "--simple", 9) == 0)
	{
		*name = "Simple";
		*comp = "O(n^2)";
	}
	else if (ft_strncmp(strategy, "--medium", 9) == 0)
	{
		*name = "Medium";
		*comp = "O(n*sqrt(n))";
	}
	else if (ft_strncmp(strategy, "--complex", 10) == 0)
	{
		*name = "Complex";
		*comp = "O(n log n)";
	}
	else
	{
		*name = "Adaptive";
		*comp = "O(n*sqrt(n))";
	}
}

static void	print_disorder(double disorder)
{
	int	disorder_int;

	disorder_int = (int)(disorder * 10000);
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(disorder_int / 100, 2);
	ft_putchar_fd('.', 2);
	if (disorder_int % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(disorder_int % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy_line(t_config *cfg)
{
	char	*strat_name;
	char	*complexity;
	char	*chosen_name;
	char	*chosen_comp;

	get_strat_name(cfg->strategy, &strat_name, &complexity);
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd(strat_name, 2);
	if (cfg->chosen)
	{
		get_strat_name(cfg->chosen, &chosen_name, &chosen_comp);
		ft_putstr_fd(" -> ", 2);
		ft_putstr_fd(chosen_name, 2);
		ft_putstr_fd(" / ", 2);
		ft_putstr_fd(chosen_comp, 2);
	}
	else
	{
		ft_putstr_fd(" / ", 2);
		ft_putstr_fd(complexity, 2);
	}
	ft_putchar_fd('\n', 2);
}

static void	print_ops_counts_1(t_config *cfg)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(cfg->op_count, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(cfg->cnt_sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(cfg->cnt_sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(cfg->cnt_ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(cfg->cnt_pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(cfg->cnt_pb, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_config *cfg, double disorder)
{
	if (!cfg)
		return ;
	print_disorder(disorder);
	print_strategy_line(cfg);
	print_ops_counts_1(cfg);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(cfg->cnt_ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(cfg->cnt_rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(cfg->cnt_rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(cfg->cnt_rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(cfg->cnt_rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(cfg->cnt_rrr, 2);
	ft_putchar_fd('\n', 2);
}
