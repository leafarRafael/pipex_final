/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:27:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/08 15:35:48 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_get_files(t_var *var, char **argv, int argc)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		var->arg->here_doc = ft_strdup(argv[1]);
		var->arg->limiter = ft_strdup(argv[2]);
		if (!var->arg->here_doc || !var->arg->limiter)
			ft_mem_alloc_error(var, "memory allocation error");
		var->s_limiter = ft_strlen(var->arg->limiter);
		var->is_here_doc = 1;
		var->nbr_cmd = argc - 4;
		var->cmd_start_position = 3;
	}
	else
	{
		var->is_here_doc = 0;
		var->nbr_cmd = argc - 3;
		var->cmd_start_position = 2;
		var->arg->file1 = ft_strdup(argv[1]);
		if (!var->arg->file1)
			ft_mem_alloc_error(var, "memory allocation error");
	}
	var->cmd_end_position = argc - 2;
	var->arg->file2 = ft_strdup(argv[argc -1]);
	if (!var->arg->file2)
		ft_mem_alloc_error(var, "memory allocation error");
}
