/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:52:55 by vegret            #+#    #+#             */
/*   Updated: 2022/12/28 10:52:55 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

bool	is_sorted(t_list *stack);
t_list	*parse_ints(int argc, char const *argv[]);
void	swap(t_list *stack);
void	rotate(t_list **stack);
void	rrotate(t_list **stack);
void	push(t_list **sender, t_list **target);

#endif
