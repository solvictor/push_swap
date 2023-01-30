/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:52:34 by vegret            #+#    #+#             */
/*   Updated: 2023/01/30 14:11:00 by vegret           ###   ########.fr       */
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

static void	three_sort(t_push_swap *ps, t_stack *s, bool (*cmp)(int, int))
{
	if (!cmp(s->head->data, s->head->next->data))
		swap(ps, s);
	if (!cmp(s->head->next->data, s->head->next->next->data))
	{
		rotate(ps, s);
		swap(ps, s);
		rrotate(ps, s);
		if (!cmp(s->head->data, s->head->next->data))
			swap(ps, s);
	}
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

static bool	smart_sort(t_push_swap *ps, t_stack *stack, size_t size, bool (*cmp)(int, int))
{
	if (size == 2 && !cmp(stack->head->data, stack->head->next->data))
		return (swap(ps, stack), true);
	if (size == 3)
		return (three_sort(ps, stack, cmp), true);
	return (false);
}

static void	quick_sort_b(t_push_swap *ps, size_t size, size_t left)
{
	int		median;
	size_t	remain;
	size_t	i;

	if (size < 2 || is_sorted(&ps->b, size, &descending)
		|| smart_sort(ps, &ps->b, size, &descending))
	{
		while (size--)
			push(ps, &ps->b, &ps->a);
		return ;
	}
	median = get_at(&ps->sorted, left + size / 2 + ((size / 2) % 2));
	remain = 0;
	i = 0;
	while (i < size)
	{
		if (ps->b.head->data >= median)
			push(ps, &ps->b, &ps->a);
		else
		{
			rotate(ps, &ps->b);
			remain++;
		}
		i++;
	}
	i = remain;
	if (remain != ps->b.size)
		while (i--)
			rrotate(ps, &ps->b);
	quick_sort(ps, size - remain, left + remain);
	quick_sort_b(ps, remain, left);
}

void	quick_sort(t_push_swap *ps, size_t size, size_t left)
{
	int		median;
	size_t	remain;
	size_t	i;

	if (size < 2 || is_sorted(&ps->a, size, &ascending)
		|| smart_sort(ps, &ps->a, size, &ascending))
		return ;
	if (size % 2)
		median = get_at(&ps->sorted, left + size / 2);
	else
		median = get_at(&ps->sorted, left + size / 2 - ((size / 2) % 2) - 1);
	remain = 0;
	i = 0;
	while (i < size)
	{
		if (ps->a.head->data <= median)
			push(ps, &ps->a, &ps->b);
		else
		{
			rotate(ps, &ps->a);
			remain++;
		}
		i++;
	}
	i = remain;
	if (remain != ps->a.size)
		while (i--)
			rrotate(ps, &ps->a);
	quick_sort(ps, remain, left + (size - remain));
	quick_sort_b(ps, size - remain, left);
}

void	frac_sort(t_push_swap *ps)
{
	const int	tier1max = get_at(&ps->sorted, ps->sorted.size / 3);
	const int	tier2max = get_at(&ps->sorted, ps->sorted.size / 3 * 2);

	while (ps->a.size > 3)
	{
		if (ps->a.head->data < tier2max)
		{
			swap(ps, &ps->a);
			if (ps->b.head->data < tier1max)
				rotate(ps, &ps->b);
		}
		else
			rotate(ps, &ps->a);
	}
	sort_three(ps, &ps->a, &ascending);
}
