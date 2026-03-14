
#include "push_swap.h"

void is_numeric(int *arr)
{
	int i = 0;
	while(arr)
	{
		if(arr[i] == '+' || arr[i] == '-' )
		{
			i++;
			if(arr[i] == '\0')
				write(2, "Error\n", 6);
		}
		ft_is_digit(arr[i]);
	}
	
}