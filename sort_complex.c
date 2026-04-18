/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:18:51 by ilcelik           #+#    #+#             */
/*   Updated: 2026/04/18 12:18:53 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bit_length(int n)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < n)
		bits++;
	return (bits);
}

static void	process_bit(t_stack **a, t_stack **b, int bit, t_config *cfg)
{
	int	size;
	int	i;

	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a, cfg);
		else
			pb(a, b, cfg);
		i++;
	}
}

void	sort_complex(t_stack **a, t_stack **b, t_config *cfg)
{
	int	n;
	int	bits;
	int	bit;

	n = stack_size(*a);
	normalize_stack(*a);
	bits = bit_length(n);
	bit = 0;
	while (bit < bits)
	{
		process_bit(a, b, bit, cfg);
		while (*b)
			pa(a, b, cfg);
		bit++;
	}
}
