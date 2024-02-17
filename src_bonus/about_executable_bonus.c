/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_executable_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:39:10 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/17 11:50:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	is_null_command(t_var *var, char c)
{
	if (c == '\0')
		ft_error_null(var, "''", 127);
}

static char	*ft_complete_path(t_var *var, int i_child)
{
	int	fd;

	if (ft_strchr(var->arg->cmd[i_child][0], '/') != NULL)
	{
		fd = open(var->arg->cmd[i_child][0], O_DIRECTORY);
		if (fd != -1)
		{
			close(fd);
			ft_common_error(var,
				var->arg->cmd[i_child][0], "Is a directory", 126);
		}
		close(fd);
		if ((access(var->arg->cmd[i_child][0], X_OK) == 0))
			return (ft_strdup(var->arg->cmd[i_child][0]));
		else
		{
			if (errno == EACCES)
				ft_common_error(var,
					var->arg->cmd[i_child][0], strerror(errno), 126);
			ft_common_error(var,
				var->arg->cmd[i_child][0], strerror(errno), 127);
		}
	}
	return (NULL);
}

char	*ft_valid_exe(t_var *var, int i_child)
{
	int		i;
	char	*temp;

	i = 0;
	is_null_command(var, var->arg->cmd[i_child][0][0]);
	temp = ft_complete_path(var, i_child);
	if (temp != NULL)
		return (temp);
	while (var->path[i])
	{
		temp = ft_strjoin(var->path[i], var->arg->cmd[i_child][0]);
		if (!temp)
			ft_mem_alloc_error(var, "memory allocation error");
		if (access(temp, X_OK | F_OK | R_OK) == 0)
			return (temp);
		free(temp);
		i++;
	}
	ft_common_error(var, var->arg->cmd[i_child][0], "command not found", 127);
	return (NULL);
}
