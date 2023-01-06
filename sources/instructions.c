/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 03:16:22 by vegret            #+#    #+#             */
/*   Updated: 2023/01/06 17:24:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	first;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = first;
}

void	push(t_stack *sender, t_stack *target)
{
	t_node	*first;

	if (!sender || !target || !sender->size)
		return ;
	first = sender->head;
	if (sender->size == 1)
		sender->head = NULL;
	else
	{
		first->prev->next = first->next;
		first->next->prev = first->prev;
		sender->head = first->next;
	}
	sender->size--;
	cicrular_doubly_list_addfront(&target->head, first);
	target->size++;
}

void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
}

void	rrotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
}
