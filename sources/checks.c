/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:20:07 by vegret            #+#    #+#             */
/*   Updated: 2023/01/25 18:32:00 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	in_list(t_node *list, int data)
{
	t_node	*first;

	if (!list)
		return (false);
	if (list->data == data)
		return (true);
	first = list;
	list = first->next;
	while (list != first)
	{
		if (list->data == data)
			return (true);
		list = list->next;
	}
	return (false);
}

bool	is_sorted(t_stack *stack, size_t size, bool (*cmp)(int, int))
{
	t_node	*list;

	list = stack->head;
	if (!list)
		return (true);
	while (--size)
	{
		if (!cmp(list->data, list->next->data))
			return (false);
		list = list->next;
	}
	return (true);
}

bool	ascending(int src, int next)
{
	return (src <= next);
}

bool	descending(int src, int next)
{
	return (src >= next);
}
