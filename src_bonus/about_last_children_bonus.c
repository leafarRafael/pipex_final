/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_last_children_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:08:51 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/08 15:49:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void ft_helper_child(t_var *var, int *i_child)
{
	var->path_exe = ft_valid_exe(var, *i_child);
	if(var->is_here_doc == 1)
		var->outfile = open (var->arg->file2, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	if( var->is_here_doc == 0)
		var->outfile = open(var->arg->file2, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (var->outfile == -1)
		ft_error(var, var->arg->file2, NULL, 1);
	dup2(var->outfile, STDOUT_FILENO);
	close(var->outfile);
	if (execve(var->path_exe, var->arg->cmd[*i_child], var->path) == -1)
		ft_error(var, var->path_exe, "command not found", 127);
}

void	ft_last_child(t_var *var, int *i_child)
{
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] < 0)
		ft_putstr_fd("error start child process", 1);
	if (var->pid[*i_child] == 0)
		ft_helper_child(var, i_child);
}
