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

static void	sort(t_list *a, t_list *b, size_t a_size, size_t b_size)
{
	if (a_size == 1 || is_sorted(a))
		return ;
	if (a_size == 2)
		return ((void) ft_printf("sa\n"));
}

void	sorttest(t_stack *a, t_stack *b)
{
	int		min_value;
	t_node	*a;
	t_node	*b;
	t_node	*min_node;
	t_node	*temp;

	while (a)
	{
		min_value = a->data;
		min_node = a;
		temp = a;
		while (temp != NULL)
		{
			if (temp->data < min_value)
			{
				min_value = temp->data;
				min_node = temp;
			}
			temp = temp->next;
		}
		while (a != min_node)
		{
			ft_printf("ra\n");
			rotate(&a);
		}
		ft_printf("pb\n");
		push(&a, &b);
		while (a && b && b->data > a->data)
		{
			ft_printf("rb\n");
			rotate(&b);
		}
	}
	while (b)
	{
		ft_printf("pa\n");
		push(&b, &a);
	}
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;

	a.head = parse_ints(argc, argv);
	b.head = NULL;
	if (argc > 1 && !a.head)
		return (ft_dprintf(2, "Error\n"), EXIT_FAILURE);
	//sort(a, b, argc - 1, 0);
	sorttest(&a, &b);
	clear_nodes(&a.head);
	clear_nodes(&b.head);
	return (EXIT_SUCCESS);
}
