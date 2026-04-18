/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:18:59 by ilcelik           #+#    #+#             */
/*   Updated: 2026/04/18 12:19:01 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_max_to_top(t_stack **b, int pos, int size, t_config *cfg)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b, cfg);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b, cfg);
	}
}

static void	push_chunk(t_stack **a, t_stack **b, int ts[2], t_config *cfg)
{
	int	pushed;
	int	rotated;
	int	size;

	pushed = 0;
	rotated = 0;
	size = stack_size(*a);
	while (pushed < ts[1] && rotated < size)
	{
		if (((*a)->index / ts[1]) == ts[0])
		{
			pb(a, b, cfg);
			pushed++;
			size--;
			rotated = 0;
		}
		else
		{
			ra(a, cfg);
			rotated++;
		}
	}
}

static void	phase1(t_stack **a, t_stack **b, t_config *cfg)
{
	int	ts[2];
	int	n;
	int	chunks;

	n = stack_size(*a);
	chunks = ft_sqrt(n);
	if (chunks < 1)
		chunks = 1;
	ts[1] = n / chunks;
	ts[0] = 0;
	while (ts[0] < chunks)
	{
		push_chunk(a, b, ts, cfg);
		ts[0]++;
	}
	while (*a)
		pb(a, b, cfg);
}

static void	phase2(t_stack **a, t_stack **b, t_config *cfg)
{
	int	size;
	int	max_pos;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = find_max_pos(*b);
		bring_max_to_top(b, max_pos, size, cfg);
		pa(a, b, cfg);
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_config *cfg)
{
	normalize_stack(*a);
	phase1(a, b, cfg);
	phase2(a, b, cfg);
}
