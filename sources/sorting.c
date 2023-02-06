/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:52:34 by vegret            #+#    #+#             */
/*   Updated: 2023/02/06 01:21:09 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_a(t_push_swap *ps, size_t nb_frac)
{
	const int	tier1max = get_at(&ps->sorted, ps->sorted.size / nb_frac);
	const int	tier2max = get_at(&ps->sorted, ps->sorted.size / nb_frac * 2);
	size_t		pushed;

	if (nb_frac < 2)
		return ;
	pushed = 0;
	while (ps->a.size > 3)
	{
		if (pushed >= ps->sorted.size / nb_frac * (nb_frac - 1)
			|| ps->a.head->data < tier2max)
		{
			push(ps, &ps->a, &ps->b);
			if (ps->b.head->data < tier1max)
				rotate(ps, &ps->b);
			pushed++;
		}
		else
			rotate(ps, &ps->a);
	}
}

static void	insert_a_sorted(t_push_swap *ps, t_node *node)
{
	size_t		moves[4];
	t_rotation	rotation;

	get_moves(ps, node, moves);
	if (moves[0] < moves[1])
		rotation.a_fun = &rotate;
	else
		rotation.a_fun = &rrotate;
	if (moves[2] < moves[3])
		rotation.b_fun = &rotate;
	else
		rotation.b_fun = &rrotate;
	rotation.a_count = smin(moves[0], moves[1]);
	rotation.b_count = smin(moves[2], moves[3]);
	make_rotations(ps, &rotation);
}

static size_t	move_count(t_push_swap *ps, t_node *node)
{
	size_t	moves[4];
	size_t	min_count;

	get_moves(ps, node, moves);
	min_count = moves[0] + moves[2];
	min_count = smin(min_count, moves[0] + moves[3]);
	min_count = smin(min_count, moves[1] + moves[2]);
	min_count = smin(min_count, moves[1] + moves[3]);
	return (min_count);
}

static t_node	*less_moves(t_push_swap *ps, t_stack *s)
{
	t_node	*tmp;
	t_node	*best;
	size_t	tmp_count;
	size_t	best_count;

	if (!s->size)
		return (NULL);
	if (s->size == 1)
		return (s->head);
	best = s->head;
	best_count = move_count(ps, best);
	tmp = s->head->next;
	while (tmp != s->head)
	{
		tmp_count = move_count(ps, tmp);
		if (tmp_count < best_count)
		{
			best = tmp;
			best_count = tmp_count;
		}
		tmp = tmp->next;
	}
	return (best);
}

void	frac_sort(t_push_swap *ps)
{
	t_node	*best;

	split_a(ps, 3);
	sort_three(ps, &ps->a, &ascending);
	while (ps->b.size)
	{
		best = less_moves(ps, &ps->b);
		insert_a_sorted(ps, best);
		push(ps, &ps->b, &ps->a);
	}
	to_head(ps, &ps->a, get_min(&ps->a));
	print_prec(ps, 0);
}
