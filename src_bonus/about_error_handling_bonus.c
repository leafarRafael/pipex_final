/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_error_handling_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:27:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/17 11:57:06 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_mem_alloc_error(t_var *var, char *str)
{
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, str, ft_strlen(str));
	ft_free_all_mem_allocation(var);
	exit(EXIT_FAILURE);
}

void	ft_common_error(t_var *var, char *file, char *error_msg, int status)
{
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, file, ft_strlen(file));
	write(STDERR_FILENO, " : ", 3);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	ft_free_all_mem_allocation(var);
	ft_close(var);
	exit(status);
}

void	ft_error_null(t_var *var, char *msg, int status)
{
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, " : ", 3);
	write(STDERR_FILENO, "command not found \n", 19);
	ft_free_all_mem_allocation(var);
	ft_close(var);
	exit(status);
}
