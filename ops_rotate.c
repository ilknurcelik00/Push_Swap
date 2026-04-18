/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:17:02 by ilcelik           #+#    #+#             */
/*   Updated: 2026/04/18 12:17:03 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	node = pop_front(stack);
	last = stack_last(*stack);
	last->next = node;
	node->prev = last;
	node->next = NULL;
}

void	ra(t_stack **a, t_config *cfg)
{
	rotate(a);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_ra++;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b, t_config *cfg)
{
	rotate(b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rb++;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b, t_config *cfg)
{
	rotate(a);
	rotate(b);
	if (cfg)
	{
		cfg->op_count++;
		cfg->cnt_rr++;
		write(1, "rr\n", 3);
	}
}
