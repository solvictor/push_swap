/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:01:44 by vegret            #+#    #+#             */
/*   Updated: 2023/01/10 23:49:28 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	parse_int(char const *str, int *dst, int *i)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1 - 2 * (str[*i] == '-');
	if (str[*i] == '-' || str[*i] == '+')
	{
		(*i)++;
		if (str[*i] < '0' || str[*i] > '9')
			return (EXIT_FAILURE);
	}
	while (str[*i] && str[*i] != ' ')
	{
		if (str[*i] < '0' || str[*i] > '9' || (value > INT_MAX && sign == 1)
			|| (value - 1 >= INT_MAX && sign == -1))
			return (EXIT_FAILURE);
		value = value * 10 + str[(*i)++] - '0';
	}
	value *= sign;
	if (value < INT_MIN || value > INT_MAX)
		return (EXIT_FAILURE);
	*dst = (int) value;
	return (EXIT_SUCCESS);
}

static bool	parse_arg(t_stack *stack, char const *str)
{
	t_node	*new;
	int		i;
	int		parsed;

	i = 0;
	while (str[i])
	{
		if (parse_int(str, &parsed, &i) || in_list(stack->head, parsed))
			return (clear_nodes(stack), EXIT_FAILURE);
		new = new_node(parsed);
		if (!new)
			return (clear_nodes(stack), EXIT_FAILURE);
		cicrular_doubly_list_addback(&stack->head, new);
		stack->size++;
		while (str[i] == ' ')
			i++;
	}
	return (EXIT_SUCCESS);
}

bool	parse_args(t_stack *stack, int argc, char const *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
		if (parse_arg(stack, argv[i++]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
