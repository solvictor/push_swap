/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:15:58 by vegret            #+#    #+#             */
/*   Updated: 2023/01/20 21:53:02 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*list;

	list = stack->head;
	if (!list)
		return (true);
	while (list->next != stack->head)
	{
		if (list->data > list->next->data)
			return (false);
		list = list->next;
	}
	return (true);
}

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

void	refresh_indexes(t_stack *stack)
{
	size_t	i;
	t_node	*tmp;

	if (!stack || !stack->head)
		return ;
	stack->head->index = 0;
	i = 1;
	tmp = stack->head->next;
	while (tmp != stack->head)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
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

void	print_stack(t_stack *stack)
{
	size_t	i;
	t_node	*current;

	if (!stack->head)
		return ;
	i = 0;
	ft_dprintf(2, "Stack %c: ", stack->name);
	current = stack->head;
	while (i < stack->size)
	{
		ft_dprintf(2, "%d ", current->data);
		current = current->next;
		i++;
	}
	ft_dprintf(2, "\n");
}
