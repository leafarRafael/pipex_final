/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:33:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/08 15:01:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "ft_printf.h"
#include "pipex_bonus.h"

void	teste_here_doc(t_var *var)
{
	pid_t pid;

	int pipe_fd[2];
	char *temp;
	int diff = 1;
    char LIMITER[5] = "EXIT";

    pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		ft_putstr_fd("here_doc >>\n", STDOUT_FILENO);
		//close(STDOUT_FILENO);
		close(pipe_fd[0]);
		while (diff == 1)
		{
			temp = get_next_line(STDIN_FILENO);
			if (ft_strncmp(temp, "EXIT", 4) == 0)
				diff = 0 ;
			ft_putstr_fd(temp, pipe_fd[1]);
			free(temp);
		}
		close(pipe_fd[1]);
		exit(EXIT_SUCCESS);
	}else
	{
		int i = 0;
		waitpid(pid, NULL, 0);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		ft_last_child(var, &i);
	}
}

int main()
{
    
            
}