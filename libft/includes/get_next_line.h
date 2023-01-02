/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:25:56 by vegret            #+#    #+#             */
/*   Updated: 2023/01/02 02:49:59 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# ifndef MAX_FILES
#  define MAX_FILES 1024
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_strlst
{
	char			content[BUFFER_SIZE + 1];
	struct s_strlst	*next;
}	t_strlst;

char		*get_next_line(int fd);
char		*get_line(t_strlst *stash, int len);
int			strindex(char *str, char c);
int			ft_strlstlen(t_strlst *stash);
t_strlst	*gnl_lstlast(t_strlst *lst);
t_strlst	*gnl_lstnew(void);
void		gnl_lstclear(t_strlst **lst);

#endif
