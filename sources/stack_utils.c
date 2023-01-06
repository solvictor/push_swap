/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:15:23 by vegret            #+#    #+#             */
/*   Updated: 2023/01/06 17:23:42 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->data = data;
	new->next = NULL;
	return (new);
}

void	cicrular_doubly_list_addback(t_node **list, t_node *new)
{
	if (list && *list)
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev->next = new;
		(*list)->prev = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		*list = new;
	}
}

void	cicrular_doubly_list_addfront(t_node **list, t_node *new)
{
	if (list && *list)
	{
		(*list)->prev->next = new;
		new->next = (*list);
		new->prev = (*list)->prev;
		(*list)->prev = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
	}
	*list = new;
}

void	clear_nodes(t_node *list)
{
	t_node	*first;
	t_node	*tmp;

	if (!list)
		return ;
	first = list;
	list = list->next;
	while (list != first)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(first);
}
