/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:15:58 by vegret            #+#    #+#             */
/*   Updated: 2023/02/06 00:34:15 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_pos(t_stack *stack, t_node *n)
{
	t_node	*tmp;
	size_t	pos;

	if (!stack || !stack->size)
		return (-1);
	pos = 0;
	tmp = stack->head;
	while (pos < stack->size)
	{
		if (tmp->data == n->data)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

int	get_at(t_stack *stack, size_t index)
{
	t_node	*tmp;

	tmp = stack->head;
	while (index-- && tmp->next)
		tmp = tmp->next;
	return (tmp->data);
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

void	list_add_sorted(t_node **list, t_node *new)
{
	t_node	*tmp;

	if (!list)
		return ;
	if (!*list || (*list)->data >= new->data)
	{
		new->next = *list;
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next && tmp->next->data < new->data)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
}

size_t	smin(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
