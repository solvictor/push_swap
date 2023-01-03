/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 03:16:22 by vegret            #+#    #+#             */
/*   Updated: 2023/01/03 11:48:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *pile)
{
	void	*tmp;

	if (!pile || !pile->next)
		return ;
	tmp = pile->content;
	pile->content = pile->next->content;
	pile->next->content = tmp;
}

static void	int_printer(void *data)
{
	ft_printf("%d ", *((int *) data));
}

static void	debug(t_list *a, t_list *b)
{
	ft_printf("A: ");
	ft_lstiter(a, int_printer);
	ft_printf("\nB: ");
	ft_lstiter(b, int_printer);
	ft_printf("\n");
}

void	push(t_list **sender, t_list **target)
{
	if (!sender || !*sender)
		return ;
	ft_lstadd_front(target, *sender);
	*sender = (*sender)->next;
}

void	rotate(t_list **pile)
{
	t_list	*first;

	if (!pile || !*pile)
		return ;
	first = *pile;
	*pile = first->next;
	first->next = NULL;
	ft_lstadd_back(pile, first);
}

void	rrotate(t_list **pile)
{
	t_list	*last;
	t_list	*newlast;

	if (!pile || !*pile)
		return ;
	last = *pile;
	newlast = NULL;
	while (last->next)
	{
		newlast = last;
		last = last->next;
	}
	if (!newlast)
		return ;
	last->next = *pile;
	*pile = last;
	newlast->next = NULL;
}
