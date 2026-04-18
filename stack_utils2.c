/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:20:07 by ilcelik           #+#    #+#             */
/*   Updated: 2026/04/18 12:22:45 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	reverse_stack(t_stack **stack)
{
	t_stack	*cur;
	int		*arr;
	int		size;
	int		i;

	size = stack_size(*stack);
	if (size <= 1)
		return ;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	cur = *stack;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	cur = *stack;
	while (cur)
	{
		cur->value = arr[--i];
		cur = cur->next;
	}
	free(arr);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	normalize_stack(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		rank;

	cur = stack;
	while (cur)
	{
		rank = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < cur->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

int	is_duplicate(t_stack *a, int val)
{
	while (a)
	{
		if (a->value == val)
			return (1);
		a = a->next;
	}
	return (0);
}
