/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:15:58 by vegret            #+#    #+#             */
/*   Updated: 2023/01/04 18:27:29 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *list)
{
	if (!list)
		return (true);
	while (list->next)
	{
		if (*(int *) list->content > *(int *) list->next->content)
			return (false);
		list = list->next;
	}
	return (true);
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
