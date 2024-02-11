/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_error_handling_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:27:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/11 10:02:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_mem_alloc_error(t_var *var, char *str)
{
	ft_putstr_fd("pipex: ", 2);
	perror(str);
	ft_free_all_mem_allocation(var);
	exit(EXIT_FAILURE);
}

void	ft_error(t_var	*var, char *str1, int error_type)
{
	if (error_type == 1)
	{
		write(STDERR_FILENO, "pipex: ", 7);
		perror(str1);
	}
	else if (error_type == 126)
	{
		write(STDERR_FILENO, "pipex: ", 7);
		perror(str1);
	}
	else if (error_type == 127)
	{
		write(STDERR_FILENO, "pipex: ", 7);
		write(STDERR_FILENO, str1, ft_strlen(str1));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "command not found", 18);
		write(STDERR_FILENO, "\n", 1);
	}
	ft_close(var);
	ft_free_all_mem_allocation(var);
	exit(error_type);
}
