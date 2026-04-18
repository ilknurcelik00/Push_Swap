/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:22:09 by ilcelik           #+#    #+#             */
/*   Updated: 2026/04/18 12:22:12 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_config(t_config *cfg)
{
	cfg->strategy = "--adaptive";
	cfg->chosen = NULL;
	cfg->bench_mode = 0;
	cfg->op_count = 0;
	cfg->cnt_sa = 0;
	cfg->cnt_sb = 0;
	cfg->cnt_ss = 0;
	cfg->cnt_pa = 0;
	cfg->cnt_pb = 0;
	cfg->cnt_ra = 0;
	cfg->cnt_rb = 0;
	cfg->cnt_rr = 0;
	cfg->cnt_rra = 0;
	cfg->cnt_rrb = 0;
	cfg->cnt_rrr = 0;
}

static void	execute_strategy(t_stack **a, t_stack **b, t_config *cfg)
{
	if (ft_strncmp(cfg->strategy, "--simple", 9) == 0)
		sort_simple(a, b, cfg);
	else if (ft_strncmp(cfg->strategy, "--medium", 9) == 0)
		sort_medium(a, b, cfg);
	else if (ft_strncmp(cfg->strategy, "--complex", 10) == 0)
		sort_complex(a, b, cfg);
	else
		sort_adaptive(a, b, cfg);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	cfg;
	double		disorder;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_config(&cfg);
	parse_args(argc, argv, &a, &cfg);
	disorder = compute_disorder(a);
	if (is_sorted(a))
	{
		if (cfg.bench_mode)
			print_bench(&cfg, disorder);
		free_stack(&a);
		return (0);
	}
	execute_strategy(&a, &b, &cfg);
	if (cfg.bench_mode)
		print_bench(&cfg, disorder);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
