/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:56:46 by vegret            #+#    #+#             */
/*   Updated: 2022/12/28 10:56:46 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	int_printer(void *data)
{
	ft_printf("%d ", *((int *) data));
}

static bool	is_sorted(t_list *list)
{
	while (list)
	{
		if (list->next && *(int *) list->content > *(int *) list->next->content)
			return (false);
		list = list->next;
	}
	return (true);
}

static void	sort(t_list *a, t_list *b)
{
	while (a || !is_sorted(b))
	{
		
	}
}

int	main(int argc, char const *argv[])
{
	t_list	*a;
	t_list	*b;

	a = parse_ints(argc, argv);
	b = NULL;
	if (!a)
		return (ft_dprintf(2, "Error\n"), EXIT_FAILURE);
	sort(a, b);
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
	return (EXIT_SUCCESS);
}
