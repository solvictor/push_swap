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

static void	sort(t_push_swap *ps)
{
	if (ps->a.size == 1 || is_sorted(&ps->a, ps->a.size, &ascending))
		return ;
	if (ps->a.size == 2)
		return ((void) ft_printf("sa\n"));
	if (ps->a.size < 4)
		return (sort_small(ps, &ps->a, &ps->b));
	frac_sort(ps);
}

int	main(int argc, char const *argv[])
{
	t_push_swap	ps;

	ps.prec = 0;
	ps.a = new_stack('a', false);
	ps.b = new_stack('b', false);
	ps.sorted = new_stack('s', true);
	if (parse_args(&ps.a, argc, argv) || presort(&ps.a, &ps.sorted))
		return (ft_dprintf(2, "Error\n"), EXIT_FAILURE);
	sort(&ps);
	clear_nodes(&ps.a);
	clear_nodes(&ps.b);
	clear_nodes(&ps.sorted);
	return (EXIT_SUCCESS);
}
