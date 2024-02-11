/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_executable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:39:10 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/11 08:56:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
char	*ft_valid_exe(t_var *var, int i_child)
{
	int		i;
	char	*temp;

	i = 0;
	if (var->arg->cmd[i_child][0][0] == '\0')
		ft_error(var, "''", 127);
	temp = ft_strdup(var->arg->cmd[i_child][0]);
	if (access(temp, X_OK | F_OK | R_OK) == 0)
		return (temp);
	free(temp);
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
	if (ft_size_matrix(var->arg->cmd[i_child][0], '/', '\0' ) > 1)
		if (access(var->arg->cmd[i_child][0], X_OK) == -1)
			ft_error(var, var->arg->cmd[i_child][0], 126);
	ft_error(var, var->arg->cmd[i_child][0], 127);
	return (NULL);
}
