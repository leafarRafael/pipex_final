/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:37:07 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/09 12:36:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_help_here_doc(t_var *var)
{
	char	*temp;

	ft_putstr_fd("here_doc >>\n", STDOUT_FILENO);
	close(var->pipe_fd[0]);
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		temp = NULL;
		temp = get_next_line(STDIN_FILENO);
		if (ft_strncmp(temp, var->arg->limiter, var->s_limiter) == 0)
		{
			free(temp);
			break ;
		}
		ft_putstr_fd(temp, var->pipe_fd[1]);
		free(temp);
	}
	close(var->pipe_fd[1]);
	ft_free_all_mem_allocation(var);
	exit(EXIT_SUCCESS);
}

void	ft_here_doc(t_var *var, int *i_child)
{
	pipe(var->pipe_fd);
	var->pid[*i_child] = fork();
	if (var->pid[*i_child] == 0)
		ft_help_here_doc(var);
	else
	{
		waitpid(var->pid[*i_child], NULL, 0);
		dup2(var->pipe_fd[0], STDIN_FILENO);
		close(var->pipe_fd[0]);
		close(var->pipe_fd[1]);
	}
}
