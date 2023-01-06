/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:01:44 by vegret            #+#    #+#             */
/*   Updated: 2023/01/06 12:24:23 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO changer return NULL
static int	parse_int(char const *str)
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
			return (NULL);
		value = value * 10 + *str++ - '0';
	}
	value *= sign;
	if (value < INT_MIN)
		return (NULL);
	return (value);
}

static bool	in_list(t_node *list, int data)
{
	while (list)
	{
		if (list->data == data)
			return (true);
		list = list->next;
	}
	return (false);
}

static t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_node	*parse_ints(int argc, char const *argv[])
{
	t_node	*list;
	t_node	*prev;
	t_node	*new;
	int		parsed;
	int		i;

	list = NULL;
	i = 0;
	while (i++ < argc)
	{
		parsed = parse_int(argv[i]);
		if (!argv[i][0] || in_list(list, parsed))
			return (clear_nodes(&list), NULL);
		new = new_node(parsed);
		if (!new)
			return (clear_nodes(&list), NULL);
		if (list)
			prev->next = new;
		else
			list = new;
		prev = new;
	}
	return (list);
}
