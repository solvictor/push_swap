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

static void	_sort(t_stack *a, t_stack *b)
{
	int		min;
	int		count;
	t_node	*tmp;

	while (b->size || !is_sorted(a))
	{
		min = a->head->data;
		tmp = a->head;
		count = a->size;
		while (count > 0)
		{
			if (tmp->next->data < min)
			{
				min = tmp->next->data;
				swap(a);
			}
			push(a, b);
			rotate(b);
			tmp = tmp->next;
			count--;
		}
		print_stack(b);
		ft_printf("Min: %d\n", min);
		count = b->size;
		while (count > 0)
		{
			if (b->head->data != min)
			{
				push(b, a);
				rrotate(a);
			}
			else
			{
				push(b, a);
				break ;
			}
			count--;
		}
		print_stack(a);
		while (a->head->data != min)
			rrotate(a);
		print_stack(a);
		ft_printf("END\n");
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 1 || is_sorted(a))
		return ;
	if (a->size == 2)
		return ((void) ft_printf("sa\n"));
	_sort(a, b);
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;

	a.head = parse_ints(argc, argv);
	a.size = argc - 1;
	b.head = NULL;
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
