/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:13:01 by ilcelik           #+#    #+#             */
/*   Updated: 2026/04/18 12:24:09 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_blank_token(char *token)
{
	int	i;

	if (!token || token[0] == '\0')
		return (1);
	i = 0;
	while (token[i] == ' ')
		i++;
	return (token[i] == '\0');
}

static void	extract_and_push(char *token, int start, int i, t_stack **a)
{
	char	tmp[32];
	int		val;
	int		k;

	k = 0;
	while (start < i)
		tmp[k++] = token[start++];
	tmp[k] = '\0';
	ft_parse_int(tmp, &val, a);
	if (is_duplicate(*a, val))
		error_exit(a, NULL);
	push_front(a, new_node(val));
}

void	parse_token(char *token, t_stack **a)
{
	int	i;
	int	start;

	if (is_blank_token(token))
		error_exit(a, NULL);
	i = 0;
	while (token[i])
	{
		while (token[i] == ' ')
			i++;
		if (!token[i])
			break ;
		start = i;
		if (token[i] == '-' || token[i] == '+')
			i++;
		if (!token[i] || token[i] < '0' || token[i] > '9')
			error_exit(a, NULL);
		while (token[i] >= '0' && token[i] <= '9')
			i++;
		if (token[i] != '\0' && token[i] != ' ')
			error_exit(a, NULL);
		extract_and_push(token, start, i, a);
	}
}
