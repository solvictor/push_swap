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
# define SA		0b000001
# define SB		0b000010
# define RA		0b000100
# define RB		0b001000
# define RRA	0b010000
# define RRB	0b100000

typedef struct s_node {
	struct s_node	*prev;
	int				data;
	struct s_node	*next;
}				t_node;

typedef struct s_stack {
	char	name;
	size_t	size;
	bool	silent;
	t_node	*head;
}				t_stack;

typedef struct s_push_swap {
	t_stack			a;
	t_stack			b;
	t_stack			sorted;
	unsigned char	opti;
}				t_push_swap;

// Parsing
bool	presort(t_stack *stack, t_stack *sorted);
bool	parse_args(t_stack *stack, int argc, char const *argv[]);

// Instructions
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	push(t_stack *sender, t_stack *target);

// Sorting
void	sort_small(t_stack *a, t_stack *b);
void	quick_sort(t_push_swap *ps, size_t size, size_t left);

// Stack manipulation
t_node	*new_node(int data);
t_stack	new_stack(char name, bool silent);
int		get_pos(t_stack *stack, t_node *n);
int		get_at(t_stack *stack, size_t index);
void	clear_nodes(t_stack *stack);
void	list_add_sorted(t_node **list, t_node *new);
void	cicrular_doubly_list_addback(t_node **list, t_node *new);
void	cicrular_doubly_list_addfront(t_node **list, t_node *new);

// Stack checks
bool	ascending(int src, int next);
bool	descending(int src, int next);
bool	in_list(t_node *list, int data);
bool	is_sorted(t_stack *stack, size_t size, bool (*cmp)(int, int));

// Debug stuff
void	print_stack(t_stack *stack);

#endif
