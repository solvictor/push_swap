/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:26:22 by vegret            #+#    #+#             */
/*   Updated: 2023/01/02 02:50:29 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlstlen(t_strlst *stash)
{
	int	len;
	int	i;

	len = 0;
	while (stash)
	{
		i = -1;
		while (stash->content[++i])
			len++;
		stash = stash->next;
	}
	return (len);
}

t_strlst	*gnl_lstlast(t_strlst *lst)
{
	t_strlst	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (lst);
}

t_strlst	*gnl_lstnew(void)
{
	t_strlst	*result;

	result = malloc(sizeof(t_strlst));
	if (!result)
		return (NULL);
	result->content[0] = '\0';
	result->next = NULL;
	return (result);
}

char	*get_line(t_strlst *stash, int len)
{
	char	*result;
	char	*tmp;
	int		i;

	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (gnl_lstclear(&stash), NULL);
	i = 0;
	while (stash)
	{
		tmp = stash->content;
		while (*tmp)
		{
			result[i++] = *tmp;
			if (*tmp == '\n')
				break ;
			tmp++;
		}
		if (*tmp == '\n')
			break ;
		stash = stash->next;
	}
	result[i] = '\0';
	return (result);
}

int	strindex(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
