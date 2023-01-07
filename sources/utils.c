/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:15:58 by vegret            #+#    #+#             */
/*   Updated: 2023/01/07 19:30:08 by vegret           ###   ########.fr       */
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

void	print_stack(t_stack *stack)
{
	size_t	i;
	t_node	*current;

	if (!stack->head)
		return ;
	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		ft_printf("%d ", current->data);
		current = current->next;
		i++;
	}
	ft_printf("\n");
}
