/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:59:10 by vegret            #+#    #+#             */
/*   Updated: 2023/01/30 22:53:42 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	run_instruction(char *instruction, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(instruction, "sa\n", 4))
		swap(NULL, a);
	else if (!ft_strncmp(instruction, "sb\n", 4))
		swap(NULL, b);
	else if (!ft_strncmp(instruction, "ss\n", 4))
		(swap(NULL, a), swap(NULL, b));
	else if (!ft_strncmp(instruction, "pa\n", 4))
		push(NULL, b, a);
	else if (!ft_strncmp(instruction, "pb\n", 4))
		push(NULL, a, b);
	else if (!ft_strncmp(instruction, "ra\n", 4))
		rotate(NULL, a);
	else if (!ft_strncmp(instruction, "rb\n", 4))
		rotate(NULL, b);
	else if (!ft_strncmp(instruction, "rr\n", 4))
		(rotate(NULL, a), rotate(NULL, b));
	else if (!ft_strncmp(instruction, "rra\n", 5))
		rrotate(NULL, a);
	else if (!ft_strncmp(instruction, "rrb\n", 5))
		rrotate(NULL, b);
	else if (!ft_strncmp(instruction, "rrr\n", 5))
		(rrotate(NULL, a), rrotate(NULL, b));
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static bool	run_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (run_instruction(line, a, b))
			return (free(line), EXIT_FAILURE);
		free(line);
		line = get_next_line(0);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char const *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (EXIT_SUCCESS);
	a = new_stack('a', true);
	b = new_stack('b', true);
	if (parse_args(&a, argc, argv) || run_instructions(&a, &b))
	{
		clear_nodes(&a);
		clear_nodes(&b);
		ft_dprintf(2, "Error\n");
		return (EXIT_FAILURE);
	}
	if (b.size == 0 && is_sorted(&a, a.size, &ascending))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_nodes(&a);
	clear_nodes(&b);
	return (EXIT_SUCCESS);
}
