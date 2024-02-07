/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_children_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:04:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/07 18:16:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_first_child(t_var *var, int *i_child)
{
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] < 0)
		ft_putstr_fd("error start child process", 2);
	if (var->pid[*i_child] == 0)
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
	else
	{
		dup2(var->pipe_fd[0], STDIN_FILENO);
		close(var->pipe_fd[0]);
		close(var->pipe_fd[1]);
	}
}

void	ft_last_child(t_var *var, int *i_child)
{
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] < 0)
		ft_putstr_fd("error start child process", 1);
	if (var->pid[*i_child] == 0)
	{
		var->path_exe = ft_valid_exe(var, *i_child);
		var->outfile = open(var->arg->file2, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (var->outfile == -1)
			ft_error(var, var->arg->file2, NULL, 1);
		dup2(var->outfile, STDOUT_FILENO);
		close(var->pipe_fd[0]);
		close(var->pipe_fd[1]);
		close(var->outfile);
		if (execve(var->path_exe, var->arg->cmd[*i_child], var->path) == -1)
			ft_error(var, var->path_exe, "command not found", 127);
	}
}
