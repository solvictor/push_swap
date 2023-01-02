/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:01:44 by vegret            #+#    #+#             */
/*   Updated: 2023/01/01 23:02:06 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*parse_int(char const *str)
{
	long	value;
	int		sign;
	int		*parsed;

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
	parsed = malloc(sizeof(int));
	if (parsed)
		*parsed = value;
	return (parsed);
}

static bool	in_list(t_list *list, int data)
{
	while (list)
	{
		if (*(int *) list->content == data)
			return (true);
		list = list->next;
	}
	return (false);
}

t_list	*parse_ints(int argc, char const *argv[])
{
	t_list	*list;
	t_list	*prev;
	t_list	*new;
	int		*parsed;
	int		i;

	list = NULL;
	prev = NULL;
	i = 1;
	while (i < argc)
	{
		parsed = parse_int(argv[i++]);
		if (!parsed || in_list(list, *parsed))
			return (ft_lstclear(&list, free), NULL);
		new = ft_lstnew(parsed);
		if (!new)
			return (ft_lstclear(&list, free), NULL);
		if (prev)
			prev->next = new;
		else
			list = new;
		prev = new;
	}
	return (list);
}