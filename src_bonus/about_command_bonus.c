/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_command_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:20:08 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/17 13:28:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_remove_space(char *str)
{
	int		i;
	char	*new_arrey;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (i == 0)
		return (str);
	new_arrey = ft_strdup(&str[i]);
	free(str);
	return (new_arrey);
}

static void	ft_cpy_array_to_matrix(char **matrix, char *str, int size_matrix)
{
	int		i;
	int		size;
	int		temp;
	char	*temp_array;

	i = 0;
	size = 0;
	temp = 0;
	while (i < size_matrix -1)
	{
		temp = ft_strlen_ch(&str[size], ' ', '\'');
		temp_array = ft_calloc(sizeof(char), temp +1);
		ft_strlcpy(temp_array, &str[size], temp);
		temp_array = ft_remove_space(temp_array);
		matrix[i] = ft_strtrim(temp_array, "'");
		free(temp_array);
		size += temp;
		i++;
	}
}

static void	ft_alloc_matrix(t_var *var, char *argv[])
{
	int	i_pointer;
	int	size_matrix;
	int	i;

	i_pointer = 0;
	i = var->cmd_start_position;
	while (i_pointer < var->nbr_cmd)
	{
		size_matrix = ft_size_matrix(argv[i], ' ', '\'' ) + 1;
		var->arg->cmd[i_pointer] = ft_calloc(sizeof(char *), size_matrix);
		if (!var->arg->cmd[i_pointer])
			ft_mem_alloc_error(var, "memory allocation error");
		ft_cpy_array_to_matrix(var->arg->cmd[i_pointer], argv[i], size_matrix);
		i++;
		i_pointer++;
	}
}

static void	ft_init_variables(t_var *var, char *argv[])
{
	var->arg->cmd = ft_calloc(sizeof(char **), var->nbr_cmd +1);
	var->pid = ft_calloc(sizeof(pid_t *), var->nbr_cmd +1);
	if (!var->arg->cmd || !var->pid)
		ft_mem_alloc_error(var, "memory allocation error");
	ft_alloc_matrix(var, argv);
}

void	ft_get_command(t_var *var, char *argv[])
{
	ft_init_variables(var, argv);
}
