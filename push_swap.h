/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarican <ssarican@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:12:18 by ssarican          #+#    #+#             */
/*   Updated: 2026/03/14 20:08:26 by ssarican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_linked_list
{
	int number;
	int index;
	struct s_linked_list *prev;
	struct s_linked_list *next;
	
} t_linked_list;

typedef enum e_method
{
	ADAPTIVE,
	SIMPLE,
    MEDIUM,   
    COMPLEX
} t_method;

int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif