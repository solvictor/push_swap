/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:56:46 by vegret            #+#    #+#             */
/*   Updated: 2022/12/28 10:56:46 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pos(t_stack *stack, t_node *n)
{
	t_node	*tmp;
	int		pos;

	if (n == stack->head)
		return (0);
	pos = 0;
	tmp = stack->head->next;
	while (tmp != n)
	{
		if (tmp == stack->head)
			return (-1);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

static void	to_head(t_stack *stack, t_node *element)
{
	void	(*r)(t_stack *);

	if (!stack || !element || stack->size < 2)
		return ;
	if (get_pos(stack, element) * 2 > (int) stack->size)
		r = &rrotate;
	else
		r = &rotate;
	while (element != stack->head)
		r(stack);
}

static void	alguez(t_stack *a, t_stack *b)
{
	t_node	*min;

	while (a->size > 1)
	{
		min = get_min(a);
		to_head(a, min);
		push(a, b);
	}
	while (b->size)
		push(b, a);
}

static int	get_at(t_stack *stack, size_t index)
{
	t_node	*tmp;

	tmp = stack->head;
	while (index-- && tmp->next)
		tmp = tmp->next;
	return (tmp->data);
}

static void	sort_three(t_stack *s)
{
	if (!s || s->size != 3 || is_sorted(s))
		return ;
	if (s->head->data > s->head->next->data)
	{
		if (s->head->data < s->head->prev->data)
			return (swap(s));
		rotate(s);
		if (s->head->data > s->head->next->data)
			swap(s);
		return ;
	}
	else if (s->head->data > s->head->prev->data)
		return (rrotate(s));
	rrotate(s);
	swap(s);
}

static void	sort_small(t_stack *a, t_stack *b)
{
	t_node	*min;

	while (a->size > 3)
	{
		min = get_min(a);
		to_head(a, min);
		push(a, b);
	}
	sort_three(a);
	while (b->size)
		push(b, a);
}

static void	sort(t_stack *a, t_stack *b, t_stack *sorted)
{
	if (a->size == 1 || is_sorted(a))
		return ;
	if (a->size == 2)
		return ((void) ft_printf("sa\n"));
	if (a->size < 6)
		return (sort_small(a, b));
	//alguez(a, b);
	quick_sort_a(a, b, sorted, a->size, 0);
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;
	t_stack	sorted;

	a = new_stack('a', false);
	b = new_stack('b', false);
	sorted = new_stack('s', true);
	if (parse_args(&a, argc, argv) || presort(&a, &sorted))
		return (ft_dprintf(2, "Error\n"), EXIT_FAILURE);
	sort(&a, &b, &sorted);
	clear_nodes(&a);
	clear_nodes(&b);
	clear_nodes(&sorted);
	return (EXIT_SUCCESS);
}
