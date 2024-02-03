/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:14:58 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/03 11:38:57 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
 #define PIPEX_BONUS_H
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char	*here_doc;
	char	*limiter;
	char	***cmd;
	char	**cmd_full;
}			t_arg;

typedef struct s_variables
{
	char	**path;
	char	*exe;
	int		i;
	int		is_here_doc;
	int		pipe[2];
	int		nbr_cmd;
	int		infile;
	int		outfile;
	int		here_doc;
	int		temp_fd;
	pid_t	*pid;
	t_arg	*arg;
}			t_var;

int		ft_printf(const char *str, ...);
void	*ft_get_struct(int type);
void	ft_valid_cpy_arguments(t_var *var, char **argv, int argc);
void	ft_put_matrix(char **matrix);
void	ft_error_during_matrix_creation(char **matrix, int i);
void	ft_error(char *str, t_var *var);
void	ft_my_error(char *str1, char *str2, t_var *var);
void	ft_get_path(t_var *var, char **envp);
void	ft_check_and_free_all_memory(t_var *var);
char	*ft_valid_exe(t_var	*var, int index);
void	ft_first_child(t_var *var, int *index_cmd);
void	ft_midle_child(t_var *var, int *index_cmd);
void	ft_last_child(t_var *var, int *index_cmd);
void	ft_fork_manager(t_var *var, int *index_cmd);

char	**ft_get_cmd_helper(char *array, char here);


void	ft_put_matrix(char **matrix);
void	ft_put_pointer_matrix(char ***pointer);
void	imprime(int *index_cmd, char *str);
void	ft_put_in_fd(int fd);

#endif