/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_first_children_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:08:02 by rbutzke           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/03 08:55:23 by rbutzke          ###   ########.fr       */
=======
/*   Updated: 2024/02/19 09:31:34 by rbutzke          ###   ########.fr       */
>>>>>>> 26a6b7645bde84ecd0d7e0d212a5bffdd6df64fa
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_first_child_helper(t_var *var, int *i_child)
{
	var->infile = open(var->arg->file1, O_RDONLY);
	if (var->infile == -1)
		ft_common_error(var, var->arg->file1, strerror(errno), 1);
	dup2(var->infile, STDIN_FILENO);
	dup2(var->pipe_fd[1], STDOUT_FILENO);
	close(var->pipe_fd[0]);
	close(var->pipe_fd[1]);
	close(var->infile);
	var->path_exe = ft_valid_exe(var, *i_child);
	if (execve(var->path_exe, var->arg->cmd[*i_child], var->path) == -1)
		ft_common_error(var, var->path_exe, strerror(errno), 1);
}

void	ft_first_child(t_var *var, int *i_child)
{
	if (pipe(var->pipe_fd) == -1)
		ft_common_error(var, "pipe definition ", strerror(errno), 3);
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] < 0)
		ft_common_error(var, "fork definition ", strerror(errno), 4);
	if (var->pid[*i_child] == 0)
		ft_first_child_helper(var, i_child);
	else
	{
		close(var->pipe_fd[1]);
		dup2(var->pipe_fd[0], STDIN_FILENO);
		close(var->pipe_fd[0]);
	}
}
