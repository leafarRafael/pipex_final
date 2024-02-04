/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:20:08 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/04 10:22:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void ft_init_pointers_cmd(t_var *var, int argc)
{
	var->nbr_cmd = argc -3;
	var->cmd_end_position = argc -2;
	var->cmd_start_position = 2;
	var->arg->cmd = ft_calloc(sizeof(char **), var->nbr_cmd +1);
	var->arg->path_cmd_full = ft_calloc(sizeof(char), var->nbr_cmd +1);
	var->arg->cmd_full = ft_calloc(sizeof(char *), var->nbr_cmd +1);
	if (!var->arg->cmd_full || !var->arg->cmd || !var->arg->path_cmd_full)
	{
		ft_printf("memory allocation error");
		exit(EXIT_FAILURE);
	}
}

static void	ft_get_cmd_full(t_var *var, char *argv[])
{
	int	i;
	int	index;

	i = var->cmd_start_position;
	index = 0;
	while (i <= var->cmd_end_position)
	{
		var->arg->cmd_full[index] = ft_strdup(argv[i]);
		var->arg->path_cmd_full[index] = ft_cp_even_my_limiter(var->arg->cmd_full[index], ' ');
		i++;
		index++;
	}
	
}

void	ft_get_cmd(t_var *var, char *argv[], int argc)
{
	ft_init_pointers_cmd(var, argc);
	ft_get_cmd_full(var, argv);
}
