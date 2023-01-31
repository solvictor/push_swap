/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:52:34 by vegret            #+#    #+#             */
/*   Updated: 2023/01/30 23:41:12 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	to_head(t_push_swap *ps, t_stack *stack, t_node *element)
{
	void	(*r)(t_push_swap *ps, t_stack *);

	if (!stack || !element || stack->size < 2)
		return ;
	if (get_pos(stack, element) * 2 > (int) stack->size)
		r = &rrotate;
	else
		r = &rotate;
	while (element != stack->head)
		r(ps, stack);
}

static t_node	*get_min(t_stack *stack)
{
	t_node	*min;
	t_node	*tmp;

	if (!stack->size)
		return (NULL);
	min = stack->head;
	tmp = stack->head->next;
	while (tmp != stack->head)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

static void	sort_three(t_push_swap *ps, t_stack *s, bool (*cmp)(int, int))
{
	if (!s || s->size != 3 || is_sorted(s, 3, cmp))
		return ;
	if (s->head->data > s->head->next->data)
	{
		if (s->head->data < s->head->prev->data)
			return (swap(ps, s));
		rotate(ps, s);
		if (s->head->data > s->head->next->data)
			swap(ps, s);
		return ;
	}
	else if (s->head->data > s->head->prev->data)
		return (rrotate(ps, s));
	rrotate(ps, s);
	swap(ps, s);
}

void	sort_small(t_push_swap *ps, t_stack *a, t_stack *b)
{
	t_node	*min;

	while (a->size > 3)
	{
		min = get_min(a);
		to_head(ps, a, min);
		push(ps, a, b);
	}
	sort_three(ps, a, &ascending);
	while (b->size)
		push(ps, b, a);
}

static void	split(t_push_swap *ps, size_t nb_frac)
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

//static t_node	*less_moves(t_push_swap *ps, t_stack *s)
//{
//	t_node	*best;
//	t_node	*tmp;

//	if (!s->size)
//		return (NULL);
//	if (s->size == 1)
//		return (s->head);
//	best = s->head;
//	tmp = s->head->next;
//	while (tmp != s->head)
//	{
//		if (ops(best) > ops(tmp))
//			best = tmp;
//		tmp = tmp->next;
//	}
//	return (best);
//}

void	frac_sort(t_push_swap *ps)
{
	t_node	*best;

	split(ps, 3);
	sort_three(ps, &ps->a, &ascending);
	// phase 2
	while (ps->b.size)
	{
		best = less_moves(ps, &ps->b);
		ops(best);
		push(ps, &ps->b, &ps->a);
	}
	to_head(ps, &ps->a, get_min(&ps->a));
	// end
	if (ps->prec & SA)
		swap(ps, &ps->a);
	if (ps->prec & SB)
		swap(ps, &ps->b);
	if (ps->prec & RA)
		rotate(ps, &ps->a);
	if (ps->prec & RB)
		rotate(ps, &ps->b);
	if (ps->prec & RRA)
		rrotate(ps, &ps->a);
	if (ps->prec & RRB)
		rrotate(ps, &ps->b);
}
