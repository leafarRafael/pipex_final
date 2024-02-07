/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_executable_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:39:10 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/07 18:16:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_valid_exe(t_var *var, int i_child)
{
	int		i;
	char	*temp;

	i = 0;
	if (access(var->arg->cmd[i_child][0], X_OK | F_OK) == 0)
		return (var->arg->cmd[i_child][0]);
	while (var->path[i])
	{
		temp = ft_strjoin(var->path[i], var->arg->cmd[i_child][0]);
		if (!temp)
			ft_mem_alloc_error(var, "memory allocation error");
		if (access(temp, X_OK | F_OK) == 0)
			return (temp);
		free(temp);
		i++;
	}
	temp = ft_strdup(var->arg->cmd[i_child][0]);
	if (!temp)
		ft_mem_alloc_error(var, "memory allocation error");
	return (temp);
}
