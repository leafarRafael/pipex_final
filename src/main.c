/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:38:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/03 16:02:22 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char *argv[], char *envp[])
{
	t_var *var;

	ft_validates_nbr_args(argc);
	var = (t_var *) ft_init_my_struct(VARIABLES);
	var->arg = (t_arg *) ft_init_my_struct(ARGUMENTS);
	ft_get_path(var, envp);
	ft_get_files(var, argv, argc);
	ft_get_cmd(var, argv, argc);
}