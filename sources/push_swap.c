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

static void	quick_sort(t_stack *A, t_stack *B)
{
	int	pivot;

	if (A->size < 2)
		return ;
	pivot = A->head->data;
	while (A->size > 1)
	{
		if (A->head->data < pivot)
			push(A, B);
		else
		{
			rotate(A);
			push(A, B);
			rrotate(B);
		}
	}
	quick_sort(B, A);
	while (B->size > 0)
	{
		push(B, A);
		rotate(A);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 1 || is_sorted(a))
		return ;
	if (a->size == 2)
		return ((void) ft_printf("sa\n"));
	quick_sort(a, b);
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;

	a.head = parse_ints(argc, argv);
	a.name = 'a';
	a.size = argc - 1;
	b.head = NULL;
	b.name = 'b';
	b.size = 0;
	if (argc > 1 && !a.head)
		return (ft_dprintf(2, "Error\n"), EXIT_FAILURE);
	sort(&a, &b);
	ft_printf("Result: ");
	print_stack(&a);
	clear_nodes(a.head);
	clear_nodes(b.head);
	return (EXIT_SUCCESS);
}
