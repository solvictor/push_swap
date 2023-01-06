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

void	sorttest(t_stack *a, t_stack *b)
{
	int		min_value;
	t_node	*node_a;
	t_node	*node_b;
	t_node	*min_node;
	t_node	*temp;

	while (node_a)
	{
		min_value = node_a->data;
		min_node = node_a;
		temp = node_a;
		while (temp != NULL)
		{
			if (temp->data < min_value)
			{
				min_value = temp->data;
				min_node = temp;
			}
			temp = temp->next;
		}
		while (node_a != min_node)
		{
			ft_printf("ra\n");
			rotate(a);
		}
		ft_printf("pb\n");
		push(a, b);
		while (node_a && node_b && node_b->data > node_a->data)
		{
			ft_printf("rb\n");
			rotate(b);
		}
	}
	while (node_b)
	{
		ft_printf("pa\n");
		push(b, a);
	}
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
	sorttest(&a, &b);
	clear_nodes(a.head);
	clear_nodes(b.head);
	return (EXIT_SUCCESS);
}
