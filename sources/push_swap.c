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
