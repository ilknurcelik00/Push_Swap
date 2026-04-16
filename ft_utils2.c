#include "push_swap.h"

void	error_exit(t_stack **a, t_stack **b)
{
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	ft_parse_int(const char *str, int *result, t_stack **a)
{
	long	val;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	val = 0;
	if (!str || !str[i])
		error_exit(a, NULL);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
		error_exit(a, NULL);
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + (str[i++] - '0');
		if ((sign == 1 && val > 2147483647) || (sign == -1
				&& val > 2147483648L))
			error_exit(a, NULL);
	}
	if (str[i] != '\0')
		error_exit(a, NULL);
	*result = (int)(val * sign);
}
