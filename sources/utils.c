/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:15:58 by vegret            #+#    #+#             */
/*   Updated: 2023/01/26 00:20:00 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_stack *stack, t_node *n)
{
	t_node	*tmp;
	int		pos;

	if (n == stack->head)
		return (0);
	pos = 0;
	tmp = stack->head->next;
	while (tmp != n)
	{
		if (tmp == stack->head)
			return (-1);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	get_at(t_stack *stack, size_t index)
{
	t_node	*tmp;

	tmp = stack->head;
	while (index-- && tmp->next)
		tmp = tmp->next;
	return (tmp->data);
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

	ft_printf("Stack %c: ", stack->name);
	if (!stack->head)
	{
		ft_printf("Empty\n");
		return ;
	}
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
