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

static void	_sort(t_stack *a, t_stack *b)
{
	t_node	*min;
	t_node	*tmp;

	while (b->size || !is_sorted(a))
	{
		if (a->size)
		{
			tmp = a->head->next;
			min = a->head;
			while (tmp != a->head)
			{
				if (tmp->data < min->data)
					min = tmp;
				tmp = tmp->next;
			}
			while (min != a->head)
				rotate(a);
			push(a, b);
		}
		else
			while (b->size)
				push(b, a);
	}
}

static void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 1 || is_sorted(a))
		return ;
	if (a->size == 2)
		return ((void) ft_printf("sa\n"));
	_sort(a, b);
}

static t_stack	new_stack(char name)
{
	t_stack	stack;

	stack.name = name;
	stack.head = NULL;
	stack.size = 0;
	return (stack);
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;

	a = new_stack('a');
	b = new_stack('b');
	if (parse_args(&a, argc, argv))
		return (ft_dprintf(2, "Error\n"), EXIT_FAILURE);
	sort(&a, &b);
	clear_nodes(&a);
	clear_nodes(&b);
	return (EXIT_SUCCESS);
}
