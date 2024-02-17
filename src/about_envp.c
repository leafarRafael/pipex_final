/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:04:44 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/17 13:01:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_path(t_var *var, char **envp)
{
	int		i;
	char	*temp;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	var->path = ft_split(&envp[i][5], ':');
	if (!var->path)
		ft_mem_alloc_error(var, "memory allocation error");
	i = 0;
	while (var->path[i])
	{
		temp = ft_strjoin(var->path[i], "/");
		if (!temp)
			ft_mem_alloc_error(var, "memory allocation error");
		free(var->path[i]);
		var->path[i] = temp;
		i++;
	}
}
