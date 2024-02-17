/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_midle_children_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:04:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/17 11:29:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_midle_child(t_var *var, int *i_child)
{
	if (pipe(var->pipe_fd) == -1)
		ft_common_error(var, "pipe definition ", strerror(errno), 3);
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] < 0)
		ft_common_error(var, "fork definition ", strerror(errno), 4);
	if (var->pid[*i_child] == 0)
	{
		close(var->pipe_fd[0]);
		dup2(var->pipe_fd[1], STDOUT_FILENO);
		close(var->pipe_fd[1]);
		var->path_exe = ft_valid_exe(var, *i_child);
		if (execve(var->path_exe, var->arg->cmd[*i_child], var->path) == -1)
			ft_common_error(var, var->path_exe, strerror(errno), 1);
	}
	else
	{
		close(var->pipe_fd[1]);
		dup2(var->pipe_fd[0], STDIN_FILENO);
		close(var->pipe_fd[0]);
	}
}
