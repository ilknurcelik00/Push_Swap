#include "push_swap.h"

static void process_split_args(char **split_arr, t_stack **a)
{
    int j;

    j = 0;
    while (split_arr[j])
    {
        if (!is_valid_syntax(split_arr[j]))
        {
            free_split_array(split_arr);
            exit_error(a, NULL);
        }
        // append_node(a, ft_atol(split_arr[j]));
        j++;
    }
}

void parse_args(int argc, char **argv, t_stack **a)
{
    int     i;
    char    **split_arr;

    i = 1;
    while (i < argc)
    {
        split_arr = ft_split(argv[i], ' ');
        if (!split_arr || !split_arr[0]) 
        {
            free_split_array(split_arr);
            exit_error(a, NULL);
        }
        process_split_args(split_arr, a);
        free_split_array(split_arr);
        i++;
    }
}
int	is_valid_syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0') // Sadece "-" veya "+" girilmişse hata!
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}