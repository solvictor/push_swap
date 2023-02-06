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
	t_stack	a;
	t_stack	b;
	t_stack	sorted;
	int		prec;
}				t_push_swap;

typedef struct s_rotation {
	size_t	a_count;
	size_t	b_count;
	void	(*a_fun)(t_push_swap *, t_stack *);
	void	(*b_fun)(t_push_swap *, t_stack *);
}				t_rotation;

// Parsing
bool	presort(t_stack *stack, t_stack *sorted);
bool	parse_args(t_stack *stack, int argc, char const *argv[]);

// Instructions
void	swap(t_push_swap *ps, t_stack *stack);
void	rotate(t_push_swap *ps, t_stack *stack);
void	rrotate(t_push_swap *ps, t_stack *stack);
void	push(t_push_swap *ps, t_stack *sender, t_stack *target);
void	print_prec(t_push_swap *ps, int action);

// Sorting
void	frac_sort(t_push_swap *ps);
void	sort_three(t_push_swap *ps, t_stack *s, bool (*cmp)(int, int));

// Stack manipulation
t_stack	new_stack(char name, bool silent);
t_node	*new_node(int data);
void	clear_nodes(t_stack *stack);
void	list_add_sorted(t_node **list, t_node *new);
void	cicrular_doubly_list_addback(t_node **list, t_node *new);
void	cicrular_doubly_list_addfront(t_node **list, t_node *new);
void	to_head(t_push_swap *ps, t_stack *stack, t_node *element);

// Stack checks
bool	ascending(int src, int next);
bool	descending(int src, int next);
bool	in_list(t_node *list, int data);
bool	is_sorted(t_stack *stack, size_t size, bool (*cmp)(int, int));

// Utils
int		get_at(t_stack *stack, size_t index);
t_node	*get_min(t_stack *stack);
size_t	smin(size_t a, size_t b);
size_t	get_pos(t_stack *stack, t_node *n);
void	make_rotations(t_push_swap *ps, t_rotation *rotation);
void	get_moves(t_push_swap *ps, t_node *node, size_t moves[4]);

#endif
