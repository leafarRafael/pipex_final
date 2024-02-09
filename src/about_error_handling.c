/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_error_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:27:57 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/09 10:52:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_mem_alloc_error(t_var *var, char *str)
{
	ft_putstr_fd("pipex: ", 2);
	perror(str);
	ft_free_all_mem_allocation(var);
	exit(EXIT_FAILURE);
}

void	ft_error(t_var	*var, char *str1, char *str2, int error_type)
{
	if (error_type == 1)
	{
		ft_putstr_fd("pipex: ", 2);
		if (str1)
			perror(str1);
		if (str2)
			ft_putstr_fd(str2, 2);
		ft_putstr_fd("\n", 2);
	}
	if (error_type == 127)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(str1, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str2, 2);
		ft_putstr_fd("\n", 2);
	}
	ft_free_all_mem_allocation(var);
	exit(error_type);
}
