/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 03:16:22 by vegret            #+#    #+#             */
/*   Updated: 2023/01/30 22:53:09 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		if (ps->prec & RA)
			ft_printf("ra\n");
		if (ps->prec & RB)
			ft_printf("rb\n");
		if (ps->prec & RRA)
			ft_printf("rra\n");
		if (ps->prec & RRB)
			ft_printf("rrb\n");
		if (((ps->prec & SA) && stack->name == 'b')
			|| ((ps->prec & SB) && stack->name == 'a'))
		{
			ft_printf("ss\n");
			ps->prec = 0;
			return ;
		}
		if (ps->prec & SA)
			ft_printf("sa\n");
		if (ps->prec & SB)
			ft_printf("sb\n");
		ps->prec = SA * (stack->name == 'a') + SB * (stack->name == 'b');
	}
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
		if (ps->prec & SA)
			ft_printf("sa\n");
		if (ps->prec & SB)
			ft_printf("sb\n");
		if (ps->prec & RA)
			ft_printf("ra\n");
		if (ps->prec & RB)
			ft_printf("rb\n");
		if (ps->prec & RRA)
			ft_printf("rra\n");
		if (ps->prec & RRB)
			ft_printf("rrb\n");
		ps->prec = 0;
		ft_printf("p%c\n", target->name);
	}
}

void	rotate(t_push_swap *ps, t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	if (!stack->silent && ps)
	{
		if (ps->prec & SA)
			ft_printf("sa\n");
		if (ps->prec & SB)
			ft_printf("sb\n");
		if (ps->prec & RRA)
			ft_printf("rra\n");
		if (ps->prec & RRB)
			ft_printf("rrb\n");
		if (((ps->prec & RA) && stack->name == 'b')
			|| ((ps->prec & RB) && stack->name == 'a'))
		{
			ft_printf("rr\n");
			ps->prec = 0;
			return ;
		}
		if (ps->prec & RA)
			ft_printf("ra\n");
		if (ps->prec & RB)
			ft_printf("rb\n");
		ps->prec = RA * (stack->name == 'a') + RB * (stack->name == 'b');
	}
}

void	rrotate(t_push_swap *ps, t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
	if (!stack->silent && ps)
	{
		if (ps->prec & SA)
			ft_printf("sa\n");
		if (ps->prec & SB)
			ft_printf("sb\n");
		if (ps->prec & RA)
			ft_printf("ra\n");
		if (ps->prec & RB)
			ft_printf("rb\n");
		if (((ps->prec & RRA) && stack->name == 'b')
			|| ((ps->prec & RRB) && stack->name == 'a'))
		{
			ft_printf("rrr\n");
			ps->prec = 0;
			return ;
		}
		if (ps->prec & RRA)
			ft_printf("rra\n");
		if (ps->prec & RRB)
			ft_printf("rrb\n");
		ps->prec = RRA * (stack->name == 'a') + RRB * (stack->name == 'b');
	}
}
