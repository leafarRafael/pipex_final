/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_first_children_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:08:02 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/08 16:21:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_children1(t_var *var, int *i_child)
{
	var->path_exe = ft_valid_exe(var, *i_child);
	var->infile = open(var->arg->file1, O_RDONLY);
	if (var->infile == -1)
		ft_error(var, var->arg->file1, NULL, 1);
	dup2(var->infile, STDIN_FILENO);
	dup2(var->pipe_fd[1], STDOUT_FILENO);
	close(var->pipe_fd[0]);
	close(var->pipe_fd[1]);
	close(var->infile);
	if (execve(var->path_exe, var->arg->cmd[*i_child], var->path) == -1)
		ft_error(var, var->path_exe, "command not found", 127);
}

void	ft_first_child(t_var *var, int *i_child)
{
	if (pipe(var->pipe_fd) < 0)
		ft_error(var, NULL, "erro open pipe_fd", 1);
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] < 0)
		ft_putstr_fd("error start child process", 2);
	if (var->pid[*i_child] == 0)
		ft_children1(var, i_child);
	else
	{
		close(var->pipe_fd[1]);
		dup2(var->pipe_fd[0], STDIN_FILENO);
		close(var->pipe_fd[0]);
	}
}
