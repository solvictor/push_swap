/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:01:44 by vegret            #+#    #+#             */
/*   Updated: 2023/01/08 23:31:57 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_int(char const *str, int *dst)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9' || value > INT_MAX / 10
			|| (value == INT_MAX / 10 && *str - '0' > 7 && sign == 1))
			return (1);
		value = value * 10 + *str++ - '0';
	}
	value *= sign;
	if (value < INT_MIN)
		return (1);
	*dst = (int) value;
	return (0);
}

t_node	*parse_ints(int argc, char const *argv[])
{
	t_node	*list;
	t_node	*new;
	int		parsed;
	int		i;

	list = NULL;
	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || ft_strlen(argv[i]) > 11
			|| parse_int(argv[i], &parsed) || in_list(list, parsed))
			return (clear_nodes(list), NULL);
		new = new_node(parsed);
		if (!new)
			return (clear_nodes(list), NULL);
		cicrular_doubly_list_addback(&list, new);
		i++;
	}
	return (list);
}
