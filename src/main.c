/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:38:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/05 18:15:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_alocation(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int main (int argc, char *argv[], char *envp[])
{
	t_var *var;

	//ft_valid_nbr_args(argc);
	var = (t_var *) ft_init_my_struct(VARIABLES);
	var->arg = (t_arg *) ft_init_my_struct(ARGUMENTS);
	ft_get_path(var, envp);
	ft_get_files(var, argv, argc);
	ft_get_command(var, argv, argc);
	ft_put_matrix(var->path);
	ft_put_pointer_matrix(var->arg->cmd);
	ft_free_all_mem_allocation(var);
	//execve("/usr/bin/grep", (char *[]) {"/usr/bin/grep", "       -v", "PIPEX_A			:= $(PIPEX_BONUS_A)", "Makefile", NULL}, 0);
}