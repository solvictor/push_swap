/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 03:16:22 by vegret            #+#    #+#             */
/*   Updated: 2023/01/26 01:59:00 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_prec(t_push_swap *ps, unsigned char cur)
{
	if (!ps)
		return ;
	if (ps->opti & SA)
		ft_printf("sa\n");
	if (ps->opti & SB)
		ft_printf("sb\n");
	if (ps->opti & RA)
		ft_printf("ra\n");
	if (ps->opti & RA)
		ft_printf("rb\n");
	if (ps->opti & RRA)
		ft_printf("rra\n");
	if (ps->opti & RRB)
		ft_printf("rrb\n");
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = stack->head->next;
	second->prev = first->prev;
	second->prev->next = second;
	first->next = second->next;
	first->next->prev = first;
	second->next = first;
	first->prev = second;
	stack->head = second;
	if (!stack->silent)
		ft_printf("s%c\n", stack->name);
}

void	swap2(t_push_swap *ps, t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = stack->head->next;
	second->prev = first->prev;
	second->prev->next = second;
	first->next = second->next;
	first->next->prev = first;
	second->next = first;
	first->prev = second;
	stack->head = second;
	if (!stack->silent)
	{
		print_prec(ps, SA * (stack->name == 'a') + SB * (stack->name == 'b'));
		ft_printf("s%c\n", stack->name);
	}
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
	if (!target->silent)
		ft_printf("p%c\n", target->name);
}

void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	if (!stack->silent)
		ft_printf("r%c\n", stack->name);
}

void	rrotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
	if (!stack->silent)
		ft_printf("rr%c\n", stack->name);
}
