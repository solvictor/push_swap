/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:15:58 by vegret            #+#    #+#             */
/*   Updated: 2023/01/06 12:26:45 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*list;

	list = stack->head;
	if (!list)
		return (true);
	while (list->next)
	{
		if (list->data > list->next->data)
			return (false);
		list = list->next;
	}
	return (true);
}

void	clear_nodes(t_node **lst)
{
	t_node	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

static void	int_printer(void *data)
{
	ft_printf("%d ", *((int *) data));
}

static void	debug(t_list *list, char *name)
{
	ft_printf("%s: ", name);
	ft_lstiter(list, int_printer);
	ft_printf("\n");
}
