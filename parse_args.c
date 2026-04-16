#include "push_swap.h"

static int	set_config_flag(char *arg, t_config *cfg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0 || ft_strncmp(arg, "--medium",
			9) == 0 || ft_strncmp(arg, "--complex", 10) == 0 || ft_strncmp(arg,
			"--adaptive", 11) == 0)
	{
		cfg->strategy = arg;
		return (1);
	}
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		cfg->bench_mode = 1;
		return (1);
	}
	if (ft_strncmp(arg, "--count-only", 13) == 0)
	{
		cfg->count_only = 1;
		return (1);
	}
	return (0);
}

static int	is_blank_token(char *token)
{
	int	i;

	if (!token || token[0] == '\0')
		return (1);
	i = 0;
	while (token[i] == ' ')
		i++;
	return (token[i] == '\0');
}

static void	extract_and_push(char *token, int start, int i, t_stack **a)
{
	char	tmp[32];
	int		val;
	int		k;

	k = 0;
	while (start < i)
		tmp[k++] = token[start++];
	tmp[k] = '\0';
	ft_parse_int(tmp, &val, a);
	if (is_duplicate(*a, val))
		error_exit(a, NULL);
	push_front(a, new_node(val));
}

static void	parse_token(char *token, t_stack **a)
{
	int	i;
	int	start;

	if (is_blank_token(token))
		error_exit(a, NULL);
	i = 0;
	while (token[i])
	{
		while (token[i] == ' ')
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
		if (token[i] != '\0' && token[i] != ' ')
			error_exit(a, NULL);
		extract_and_push(token, start, i, a);
	}
}

void	parse_args(int argc, char **argv, t_stack **a, t_config *cfg)
{
	int	i;

	if (argc == 1)
		exit(0);
	cfg->strategy = "--adaptive";
	cfg->count_only = 0;
	cfg->bench_mode = 0;
	i = 1;
	while (i < argc && set_config_flag(argv[i], cfg))
		i++;
	if (i >= argc)
		exit(0);
	while (i < argc)
	{
		parse_token(argv[i], a);
		i++;
	}
	reverse_stack(a);
}
