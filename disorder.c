/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:16:19 by ilcelik           #+#    #+#             */
/*   Updated: 2026/04/18 12:16:21 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i] = stack->value;
		i++;
		stack = stack->next;
	}
	return (arr);
}

static double	calculate_ratio(int *arr, int size)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			total_pairs++;
			if (arr[i] > arr[j])
				mistakes++;
		}
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

double	compute_disorder(t_stack *a)
{
	int		*arr;
	int		size;
	double	ratio;

	size = stack_size(a);
	if (size <= 1)
		return (0.0);
	arr = stack_to_array(a, size);
	if (!arr)
		return (1.0);
	ratio = calculate_ratio(arr, size);
	free(arr);
	return (ratio);
}
