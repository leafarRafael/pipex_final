/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:04:44 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/03 13:17:39 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_path(t_var *var, char **envp)
{
	int		i;
	char	*temp;

	i = 0;
	while (ft_strncmp(envp[++i], "PATH=/", 5));
	var->path = ft_split(&envp[i][5], ':');
	i = 0;
	while (var->path[i])
	{
		temp = ft_strjoin(var->path[i], "/");
		if (!temp)
		{
			ft_printf("memory allocation error");
			exit(EXIT_FAILURE);
		}
		free(var->path[i]);
		var->path[i] = temp;
		i++;
	}
}