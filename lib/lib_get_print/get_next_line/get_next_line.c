/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:36:57 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/16 11:00:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	remode_buffer(char *buffer, int index)
{
	int	i;
	int	j;

	j = index;
	i = 0;
	while (buffer[j] != 0)
	{
		buffer[i] = buffer[j];
		i++;
		j++;
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
}

void	cpy_buff_to_lst(char *buffer, t_lst **lst, int *is_space)
{
	int	index;

	index = 0;
	while (buffer[index] != '\0')
	{
		ft_lst_add_creat(lst, buffer[index]);
		if (buffer[index] == '\n')
		{
			*is_space = 1;
			buffer[index] = 0;
			index++;
			remode_buffer(buffer, index);
			break ;
		}
		buffer[index] = 0;
		index++;
	}
}

t_lst	*ft_read_files(int fd)
{
	static char	buffer[BUFFER_SIZE +1];
	t_lst		*lst;
	int			bytes_read;
	int			is_space;

	is_space = 0;
	bytes_read = 1;
	lst = NULL;
	cpy_buff_to_lst(buffer, &lst, &is_space);
	while (bytes_read > 0 && !is_space)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			clear(lst);
			return (0);
		}
		cpy_buff_to_lst(buffer, &lst, &is_space);
		buffer[bytes_read +1] = '\0';
	}
	return (lst);
}

char	*get_next_line(int fd)
{
	char	*next_line;
	t_lst	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lst = NULL;
	lst = ft_read_files(fd);
	if (!lst)
		return (NULL);
	next_line = cpy_lst_array(lst);
	if (!next_line)
		return (NULL);
	return (next_line);
}
