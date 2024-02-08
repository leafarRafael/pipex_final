/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:38:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/08 16:05:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_fork_manager(t_var *var, int *i_child)
{
	if (var->is_here_doc == 0)
		ft_first_child(var, i_child);
	if (var->is_here_doc == 1)
		ft_here_doc(var, i_child);
	(*i_child)++;
	while ((*i_child) != var->nbr_cmd -1)
	{
		ft_midle_child(var, i_child);
		(*i_child)++;
	}
	ft_last_child(var, i_child);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_var	*var;
	int		i_child;

	i_child = 0;
	ft_valid_nbr_args(argc);
	var = (t_var *) ft_init_my_struct(VARIABLES);
	var->arg = (t_arg *) ft_init_my_struct(ARGUMENTS);
	ft_get_path(var, envp);
	ft_get_files(var, argv, argc);
	ft_get_command(var, argv, argc);
	ft_fork_manager(var, &i_child);
	waitpid(var->pid[i_child], &var->exit_status, 0);
	ft_free_all_mem_allocation(var);
	return (get_exit_status(var->exit_status));
}
