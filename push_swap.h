/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilcelik <ilcelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:12:18 by ssarican          #+#    #+#             */
/*   Updated: 2026/03/16 17:35:40 by ilcelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int number;
	int index;
	struct s_stack *prev;
	struct s_stack *next;
	
} t_stack;

typedef enum e_method
{
	ADAPTIVE,
	SIMPLE,
    MEDIUM,   
    COMPLEX
} t_method;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
void parse_args(int argc, char **argv, t_stack **a);
int is_valid_syntax(char *str);
long ft_atol(const char *str);
int has_duplicate(t_stack *a, int num);
void free_split(char **split_arr);
void free_stack(t_stack **stack);
void exit_error(t_stack **a, char **split_arr);

#endif