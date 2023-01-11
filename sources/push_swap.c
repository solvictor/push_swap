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

static void	alguez(t_stack *a, t_stack *b)
{
	t_node	*min;
	t_node	*tmp;
	void	(*r)(t_stack *);

	while (a->size > 1)
	{
		tmp = a->head->next;
		min = a->head;
		while (tmp != a->head)
		{
			if (tmp->data < min->data)
				min = tmp;
			tmp = tmp->next;
		}
		if (get_pos(a, min) * 2 > (int) a->size)
			r = &rrotate;
		else
			r = &rotate;
		while (min != a->head)
			r(a);
		push(a, b);
	}
	while (b->size)
		push(b, a);
}

static void	sort_small(t_stack *a, t_stack *b)
{
	
}

static void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 1 || is_sorted(a))
		return ;
	if (a->size == 2)
		return ((void) ft_printf("sa\n"));
	if (a->size < 6)
		return (sort_small(a, b));
	alguez(a, b);
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;

	a = new_stack('a', false);
	b = new_stack('b', false);
	if (parse_args(&a, argc, argv))
		return (ft_dprintf(2, "Error\n"), EXIT_FAILURE);
	sort(&a, &b);
	clear_nodes(&a);
	clear_nodes(&b);
	return (EXIT_SUCCESS);
}
