/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:13:01 by ilcelik           #+#    #+#             */
/*   Updated: 2026/04/18 12:24:09 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*parse_strategy(char *arg)
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

static int	is_mode_flag(char *arg)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		return (1);
	return (0);
}

static void	set_flag(t_config *cfg, char *arg)
{
	if (parse_strategy(arg))
		cfg->strategy = parse_strategy(arg);
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		cfg->bench_mode = 1;
}

static void	parse_flags(int *i, int argc, char **argv, t_config *cfg)
{
	while (*i < argc && (parse_strategy(argv[*i]) || is_mode_flag(argv[*i])))
	{
		set_flag(cfg, argv[*i]);
		(*i)++;
	}
}

void	parse_args(int argc, char **argv, t_stack **a, t_config *cfg)
{
	int	i;

	if (argc == 1)
		exit(0);
	cfg->strategy = "--adaptive";
	cfg->bench_mode = 0;
	i = 1;
	parse_flags(&i, argc, argv, cfg);
	if (i >= argc)
		exit(0);
	while (i < argc)
	{
		parse_token(argv[i], a);
		i++;
	}
	reverse_stack(a);
}
