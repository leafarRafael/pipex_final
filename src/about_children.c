/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_children.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:04:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/06 09:44:35 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_child(t_var *var, int *i_child)
{
    int pipe_fd[2];
    pid_t pid;

    if (pipe(pipe_fd) < 0)
        ft_error(var, "erro open pipe_fd");
    pid = fork();
    if (pid < 0)
        ft_error(var, "error start child process");
    if (pid == 0)
    {
        var->path_exe =  ft_valid_exe(var, *i_child);
        var->infile = open(var->arg->file1, O_RDONLY);
        dup2(var->infile, STDIN_FILENO);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        close(var->infile);
        if (execve(var->path_exe, var->arg->cmd[*i_child], var->path) == -1)
			perror(strerror(errno));
    }
    else
    {
        dup2(pipe_fd[0], STDIN_FILENO);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        (*i_child)++;
    }
}

void	ft_last_child(t_var *var, int *i_child)
{
    int pipe_fd[2];
    pid_t pid;

    if (pipe(pipe_fd) < 0)
        ft_error(var, "erro open pipe_fd");
    pid = fork();
    if (pid < 0)
        ft_error(var, "error start child process");
    if (pid == 0)
    {
        var->path_exe =  ft_valid_exe(var, *i_child);
        var->outfile = open(var->arg->file2, O_RDWR | O_CREAT | O_TRUNC, 0666);;
        dup2(var->outfile, STDOUT_FILENO);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        close(var->outfile);
        ft_put_pointer_matrix(var->arg->cmd);
        if (execve(var->path_exe, var->arg->cmd[*i_child], var->path) == -1)
			perror(strerror(errno));
    }
}