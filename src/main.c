/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:38:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/11 10:17:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(t_var *var)
{
	close(var->pipe_fd[1]);
	close(var->pipe_fd[0]);
	close(STDERR_FILENO);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
}

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
	ft_close(var);
	waitpid(var->pid[i_child], &var->exit_status, 0);
	ft_free_all_mem_allocation(var);
	return (get_exit_status(var->exit_status));
}
