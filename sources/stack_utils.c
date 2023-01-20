/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:15:23 by vegret            #+#    #+#             */
/*   Updated: 2023/01/20 21:23:41 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	new_stack(char name, bool silent)
{
	t_stack	stack;

	stack.name = name;
	stack.head = NULL;
	stack.sorted = NULL;
	stack.size = 0;
	stack.silent = silent;
	return (stack);
}

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

void	clear_nodes(t_stack *stack)
{
	t_node	*tmp;
	t_node	*list;
	t_node	*first;

	if (!stack->head)
		return ;
	first = stack->head;
	list = first->next;
	while (list != first)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(first);
	list = stack->sorted;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
