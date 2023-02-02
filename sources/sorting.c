/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:52:34 by vegret            #+#    #+#             */
/*   Updated: 2023/02/02 02:08:29 by vegret           ###   ########.fr       */
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

static size_t	insert_index(t_stack *stack, int data)
{
	t_node	*tmp;
	size_t	index;

	if (!stack || !stack->size)
		return (0);
	index = 0;
	tmp = stack->head;
	while (index < stack->size)
	{
		if (tmp->data >= data)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static size_t	move_count(t_push_swap *ps, t_node *node)
{
	const size_t	ra = insert_index(&ps->a, node->data);
	const size_t	rra = ps->a.size - ra;
	const size_t	rb = get_pos(&ps->b, node);
	const size_t	rrb = ps->b.size - rb;

	return (min(ra + rb, min(ra + rrb, min(rra + rb, rra + rrb))));
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
	ft_printf("best count: %d\n", best_count);
	move_count(ps, best);
	return (best);
}

static void	_insert_a_sorted(t_push_swap *ps, size_t count_a, size_t count_b,
					void (*a_fun)(t_push_swap *, t_stack *),
					void (*b_fun)(t_push_swap *, t_stack *))
{
	while (count_a || count_b)
	{
		if (count_a)
		{
			a_fun(ps, &ps->a);
			count_a--;
		}
		if (count_b)
		{
			b_fun(ps, &ps->b);
			count_b--;
		}
	}
}

static void	insert_a_sorted(t_push_swap *ps, t_node *node)
{
	const size_t	rb = get_pos(&ps->b, node);
	const size_t	rrb = ps->b.size - rb;
	const size_t	ra = insert_index(&ps->a, node->data);
	const size_t	rra = ps->a.size - ra;
	void			(*a_fun)(t_push_swap *, t_stack *);
	void			(*b_fun)(t_push_swap *, t_stack *);

	if (ra < rra)
		a_fun = &rotate;
	else
		a_fun = &rrotate;
	if (rb < rrb)
		b_fun = &rotate;
	else
		b_fun = &rrotate;
	_insert_a_sorted(ps, min(ra, rra), min(rb, rrb), a_fun, b_fun);
}

void	frac_sort(t_push_swap *ps)
{
	t_node	*best;

	split(ps, 3);
	sort_three(ps, &ps->a, &ascending);
	// phase 2
	while (ps->b.size)
	{
		best = less_moves(ps, &ps->b);
		insert_a_sorted(ps, best);
		push(ps, &ps->b, &ps->a);
	}
	to_head(ps, &ps->a, get_min(&ps->a));
	// end
	print_prec(ps, 0);
}
