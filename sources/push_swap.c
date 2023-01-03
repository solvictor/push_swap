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

static void	sort(t_list *a, t_list *b)
{
	while (b || !is_sorted(a))
	{
		if (ft_lstsize(a) > 1 && ft_lstsize(b) > 1
			&& *(int *) a->content > *(int *) a->next->content
			&& *(int *) b->content < *(int *) b->next->content)
		{
			(ft_printf("ss\n"), swap(a), swap(b));
			continue ;
		}
		if (ft_lstsize(a) > 1
			&& *(int *) a->content > *(int *) a->next->content)
		{
			(ft_printf("sa\n"), swap(a));
			continue ;
		}
		if (ft_lstsize(b) > 1
			&& *(int *) b->content < *(int *) b->next->content)
		{
			(ft_printf("sb\n"), swap(a));
			continue ;
		}
	}
}

int	main(int argc, char const *argv[])
{
	t_list	*a;
	t_list	*b;

	a = parse_ints(argc, argv);
	b = NULL;
	if (argc > 1 && !a)
		return (ft_dprintf(2, "Error\n"), EXIT_FAILURE);
	sort(a, b);
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
	return (EXIT_SUCCESS);
}
