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

static void	int_printer(void *data)
{
	ft_printf("%d ", *((int *) data));
}

static void	swap(t_list *pile)
{
	void	*tmp;

	if (!pile || !pile->next)
		return ;
	tmp = pile->content;
	pile->content = pile->next->content;
	pile->next->content = tmp;
}

/*
	push first element of sender to target
*/
static void	push(t_list **sender, t_list **target)
{
	t_list	*first;

	if (!sender || !*sender)
		return ;
	first = *sender;
	*sender = first->next;
	first->next = *target;
	*target = first;
}

static void	rotate(t_list **pile)
{
	t_list	*first;

	if (!pile || !*pile)
		return ;
	first = *pile;
	*pile = first->next;
	first->next = NULL;
	ft_lstadd_back(pile, first);
}

static void	rrotate(t_list **pile)
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

static void	ps_sort(t_list *a, t_list *b)
{

}

int	main(int argc, char const *argv[])
{
	t_list	*a;
	t_list	*b;

	a = parse_ints(argc, argv);
	b = parse_ints(argc, argv);
	if (!a)
		return (ft_dprintf(2, "Error\n"), EXIT_FAILURE);
	ps_sort(a, b);

	ft_printf("A: ");
	ft_lstiter(a, int_printer);
	ft_printf("\nB: ");
	ft_lstiter(b, int_printer);

	ft_printf("\nra\n");
	rotate(&a);

	ft_printf("A: ");
	ft_lstiter(a, int_printer);
	ft_printf("\nB: ");
	ft_lstiter(b, int_printer);

	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
	return (EXIT_SUCCESS);
}
