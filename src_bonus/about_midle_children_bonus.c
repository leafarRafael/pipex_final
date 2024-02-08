/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_midle_children_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:04:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/08 16:22:20 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_midle_child(t_var *var, int *i_child)
{
	if (pipe(var->pipe_fd) < 0)
		ft_error(var, NULL, "erro open pipe_fd", 1);
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] < 0)
		ft_putstr_fd("error start child process", 1);
	if (var->pid[*i_child] == 0)
	{
		var->path_exe = ft_valid_exe(var, *i_child);
		close(var->pipe_fd[0]);
		dup2(var->pipe_fd[1], STDOUT_FILENO);
		close(var->pipe_fd[1]);
		if (execve(var->path_exe, var->arg->cmd[*i_child], var->path) == -1)
			ft_error(var, var->path_exe, "command not found", 127);
	}
	else
	{
		close(var->pipe_fd[1]);
		dup2(var->pipe_fd[0], STDIN_FILENO);
		close(var->pipe_fd[0]);
	}
}
