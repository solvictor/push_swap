/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 03:16:22 by vegret            #+#    #+#             */
/*   Updated: 2023/02/01 01:32:05 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_prec(t_push_swap *ps, int cur)
{
	int	match;

	match = 0;
	if (ps->prec == SA && cur != SB)
		ft_printf("sa\n");
	if (ps->prec == SB && cur != SA)
		ft_printf("sb\n");
	if (ps->prec == RA && cur != RB)
		ft_printf("ra\n");
	if (ps->prec == RB && cur != RA)
		ft_printf("rb\n");
	if (ps->prec == RRA && cur != RRB)
		ft_printf("rra\n");
	if (ps->prec == RRB && cur != RRA)
		ft_printf("rrb\n");
	if ((ps->prec == SA && cur == SB) || (ps->prec == SB && cur == SA))
		match = ft_printf("ss\n");
	if ((ps->prec == RA && cur == RB) || (ps->prec == RB && cur == RA))
		match = ft_printf("rr\n");
	if ((ps->prec == RRA && cur == RRB) || (ps->prec == RRB && cur == RRA))
		match = ft_printf("rrr\n");
	if (match)
		ps->prec = 0;
	else
		ps->prec = cur;
}

void	swap(t_push_swap *ps, t_stack *stack)
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
	if (!stack->silent && ps)
		print_prec(ps, SA * (stack->name == 'a') + SB * (stack->name == 'b'));
}

void	push(t_push_swap *ps, t_stack *sender, t_stack *target)
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
	if (!target->silent && ps)
	{
		print_prec(ps, 0);
		ft_printf("p%c\n", target->name);
	}
}

void	rotate(t_push_swap *ps, t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	if (!stack->silent && ps)
		print_prec(ps, RA * (stack->name == 'a') + RB * (stack->name == 'b'));
}

void	rrotate(t_push_swap *ps, t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
	if (!stack->silent && ps)
		print_prec(ps, RRA * (stack->name == 'a') + RRB * (stack->name == 'b'));
}
