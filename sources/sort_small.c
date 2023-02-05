/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:38:30 by vegret            #+#    #+#             */
/*   Updated: 2023/02/05 02:29:07 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_head(t_push_swap *ps, t_stack *stack, t_node *element)
{
	void	(*r)(t_push_swap *ps, t_stack *);

	if (!stack || !element || stack->size < 2)
		return ;
	if (get_pos(stack, element) * 2 > stack->size)
		r = &rrotate;
	else
		r = &rotate;
	while (element != stack->head)
		r(ps, stack);
}

t_node	*get_min(t_stack *stack)
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

void	sort_three(t_push_swap *ps, t_stack *s, bool (*cmp)(int, int))
{
	if (!s || s->size > 3 || is_sorted(s, 3, cmp))
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
	print_prec(ps, 0);
}
