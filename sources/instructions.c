/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 03:16:22 by vegret            #+#    #+#             */
/*   Updated: 2023/01/04 18:26:37 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	void	*first;

	if (!stack || !stack->next)
		return ;
	first = stack->content;
	stack->content = stack->next->content;
	stack->next->content = first;
}

void	push(t_list **sender, t_list **target)
{
	t_list	*first;

	if (!sender || !*sender)
		return ;
	first = *sender;
	*sender = (*sender)->next;
	first->next = NULL;
	ft_lstadd_front(target, first);
}

void	rotate(t_list **stack)
{
	t_list	*first;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}

void	rrotate(t_list **stack)
{
	t_list	*last;
	t_list	*newlast;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	last = *stack;
	newlast = NULL;
	while (last->next)
	{
		newlast = last;
		last = last->next;
	}
	if (!newlast)
		return ;
	last->next = *stack;
	*stack = last;
	newlast->next = NULL;
}
