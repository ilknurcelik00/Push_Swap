#include "push_swap.h"

int main( int argc, char **argv)
{
	t_linked_list *a;
	t_linked_list *b;
	int i;
	t_method method;
	int is_benchmark;

	method = ADAPTIVE; 
    is_benchmark = 0;

	a = NULL;
	b = NULL;
	i = 1;

	if(argc == 1)
		return 0;
	
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
    {
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
            method = SIMPLE;
        else if (ft_strncmp(argv[i], "--medium", 9) == 0)
            method = MEDIUM;
        else if (ft_strncmp(argv[i], "--complex", 10) == 0)
            method = COMPLEX;
        else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
            method = ADAPTIVE;
        else if (ft_strncmp(argv[i], "--bench", 8) == 0)
            is_benchmark = 1;
        else
            break;
		i++;
	}

	if(i >= argc)
		return(0);
	
	return(0);
}