/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:38:05 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/16 10:29:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_lst
{
	char			c;
	struct s_lst	*next;
}	t_lst;

void	remode_buffer(char *buffer, int index);
void	cpy_buff_to_lst(char *buffer, t_lst **lst, int *is_space);
t_lst	*ft_read_files(int fd);
char	*get_next_line(int fd);
void	ft_lst_add_creat(t_lst **lst, char content);
char	*cpy_lst_array(t_lst *lst);
void	clear(t_lst *lst);
int		ft_lstlen(t_lst *lst);

#endif