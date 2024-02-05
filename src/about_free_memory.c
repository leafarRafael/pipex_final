/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_free_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:45:42 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/05 18:05:10 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void ft_free(void *pointer)
{
    free(pointer);
    pointer = NULL;
}

static void ft_free_matrix(char **matrix)
{
    int i;

    i = 0;
    while(matrix[i])
    {
        free(matrix[i]);
        matrix[i] = NULL;
        i++;
    }
    free(matrix);
    matrix = NULL;
}

static void ft_free_pointer_matrix(char ***pointer)
{
    int i;

    i = 0;
    while (pointer[i])
    {
        ft_free_matrix(pointer[i]);
        pointer[i] = NULL;
        i++;
    }
    free(pointer);
    pointer = NULL;
}

void    ft_free_all_mem_allocation(t_var *var)
{
    if (var->arg->file1)
        ft_free(var->arg->file1);
    if (var->arg->file2)
        ft_free(var->arg->file2);
    if (var->arg->cmd)
        ft_free_pointer_matrix(var->arg->cmd);
    if (var->path)
        ft_free_matrix(var->path);
}