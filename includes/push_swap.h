/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:52:55 by vegret            #+#    #+#             */
/*   Updated: 2022/12/28 10:52:55 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_node {
	struct s_node	*prev;
	int				data;
	struct s_node	*next;
}				t_node;

typedef struct s_stack {
	t_node	*head;
	char	name;
	size_t	size;
}				t_stack;

// Parsing
t_node	*parse_ints(int argc, char const *argv[]);

// Instructions
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	push(t_stack *sender, t_stack *target);

// Stack manipulation
t_node	*new_node(int data);
void	clear_nodes(t_node *list);
void	cicrular_doubly_list_addback(t_node **list, t_node *new);
void	cicrular_doubly_list_addfront(t_node **list, t_node *new);

// Stack checks
bool	is_sorted(t_stack *stack);
bool	in_list(t_node *list, int data);

// Debug stuff
void	print_stack(t_stack *stack);

#endif
