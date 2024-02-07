/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:38:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/07 18:17:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_var	*var;
	int		i_child;

	i_child = 0;
	ft_valid_nbr_args(argc);
	var = (t_var *) ft_init_my_struct(VARIABLES);
	var->arg = (t_arg *) ft_init_my_struct(ARGUMENTS);
	ft_get_path(var, envp);
	ft_get_files(var, argv, argc);
	ft_get_command(var, argv, argc);
	if (pipe(var->pipe_fd) < 0)
		ft_mem_alloc_error(var, "erro open pipe_fd");
	ft_first_child(var, &i_child);
	i_child++;
	ft_last_child(var, &i_child);
	waitpid(var->pid[i_child], &var->exit_status, 0);
	ft_free_all_mem_allocation(var);
	return (get_exit_status(var->exit_status));
}
