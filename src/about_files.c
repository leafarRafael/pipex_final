/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:27:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/07 18:02:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_files(t_var *var, char **argv, int argc)
{
	var->arg->file1 = ft_strdup(argv[1]);
	var->arg->file2 = ft_strdup(argv[argc -1]);
	if (!var->arg->file1 || !var->arg->file2)
		ft_mem_alloc_error(var, "memory allocation error");
}
