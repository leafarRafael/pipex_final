/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:14:58 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/07 14:15:34 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
 #define PIPEX_H
#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "ft_printf.h"

# define CMD_NOT_FOUND "command not found\n"

typedef enum e_my_structs
{
	VARIABLES = 0,
	ARGUMENTS,
}		t_my_structs;

typedef enum e_error
{
	ALLOC_MEMORY = 0,
	ERROR_ALLOC_MATRIX,
	OTHERS,
}		t_error;

typedef	struct t_arguments
{
	char	*file1;
	char	*file2;
	char	***cmd;
}			t_arg;

typedef struct s_variables
{
	char	**path;
	char	*path_exe;
	int		infile;
	int		outfile;
	int		cmd_start_position;
	int		cmd_end_position;
	int		nbr_cmd;
	int		size;
	t_arg	*arg;
}			t_var;

void	ft_valid_nbr_args(int argc);
void	*ft_init_my_struct(int type);
void	ft_get_path(t_var *var, char **envp);
void	ft_get_files(t_var *var, char **argv, int argc);
void	ft_get_command(t_var *var, char *argv[], int argc);
int		ft_size_matrix(char *str, char c_to_count, char delimiter);
int		ft_strlen_ch(char *str, char stop_if, char ignore_if);
void	ft_error(t_var *var, char *str);
void    ft_free_all_mem_allocation(t_var *var);
char    *ft_valid_exe(t_var *var, int i_child);
void	ft_first_child(t_var *var, int *i_child);
void	ft_last_child(t_var *var, int *i_child);



void	ft_put_matrix(char **matrix);
void	ft_put_pointer_matrix(char ***pointer);




#endif