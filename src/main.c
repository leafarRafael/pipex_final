/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:38:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/06 09:42:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(t_var *var, char *str)
{
	perror(str);
	ft_free_all_mem_allocation(var);
	exit(EXIT_FAILURE);
}

int main (int argc, char *argv[], char *envp[])
{
	t_var	*var;
	int 	i_child;

	i_child = 0;
	ft_valid_nbr_args(argc);
	var = (t_var *) ft_init_my_struct(VARIABLES);
	var->arg = (t_arg *) ft_init_my_struct(ARGUMENTS);
	ft_get_path(var, envp);
	ft_get_files(var, argv, argc);
	ft_get_command(var, argv, argc);
	ft_first_child(var, &i_child);
	ft_last_child(var, &i_child);
	ft_free_all_mem_allocation(var);
}