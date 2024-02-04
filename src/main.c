/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:38:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/04 13:03:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char *argv[], char *envp[])
{
	t_var *var;

	ft_valid_nbr_args(argc);
	var = (t_var *) ft_init_my_struct(VARIABLES);
	var->arg = (t_arg *) ft_init_my_struct(ARGUMENTS);
	ft_get_path(var, envp);
	ft_get_files(var, argv, argc);
	ft_get_cmd(var, argv, argc);
	ft_put_matrix(var->path);
	execve("/usr/bin/grep", (char *[]) {"/usr/bin/grep", "-v", "PIPEX_A			:= $(PIPEX_BONUS_A)", "Makefile", NULL}, 0);
}