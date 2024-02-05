/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:20:08 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/05 18:04:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void ft_cpy_array_to_matrix(char **matrix, char *str, int size_matrix)
{
    int i;
    int size;
    int temp;
    char *string;

    i = 0;
    size = 0;
    temp = 0;
    while(i < size_matrix -1)
    {     
        temp = ft_strlen_ch(&str[size], ' ', '\'');
        matrix[i] = ft_calloc(sizeof(char), temp +1);
        ft_strlcpy(matrix[i], &str[size], temp);
        size += temp;
        i++;
    }
}

static void ft_alloc_matrix(t_var *var, char *argv[], int argc)
{
    int i_pointer;
    int size_matrix;
    int i;

    i_pointer = 0;
    i = var->cmd_start_position;
    while (i_pointer < var->nbr_cmd)
    {
        size_matrix = ft_size_matrix(argv[i], ' ', '\'' ) +1;
        var->arg->cmd[i_pointer] = ft_calloc(sizeof(char *), size_matrix);
        if(!var->arg->cmd[i_pointer])
            ft_error_alocation("memory allocation error");
        ft_cpy_array_to_matrix(var->arg->cmd[i_pointer], argv[i],size_matrix);
        i++;
        i_pointer++;
    }
}

static void ft_init_variables(t_var *var, char *argv[], int argc)
{
    var->cmd_start_position = 2;
    var->cmd_end_position = argc-2;
    var->nbr_cmd = argc -3;
    var->arg->cmd = ft_calloc(sizeof(char **), var->nbr_cmd +1);
    if (!var->arg->cmd)
        ft_error_alocation("memory allocation error");
    ft_alloc_matrix(var, argv, argc);
}
void	ft_get_command(t_var *var, char *argv[], int argc)
{
    ft_init_variables(var, argv, argc);
}