/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:16:55 by ilcelik           #+#    #+#             */
/*   Updated: 2026/04/18 12:16:57 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	push_front(stack, last);
}

void	rra(t_stack **a, t_config *cfg)
{
	rev_rotate(a);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rra++;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b, t_config *cfg)
{
	rev_rotate(b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rrb++;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b, t_config *cfg)
{
	rev_rotate(a);
	rev_rotate(b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rrr++;
		write(1, "rrr\n", 4);
	}
}
