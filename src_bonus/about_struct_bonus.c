/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_struct_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:44:35 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/07 18:16:53 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	*ft_init_my_struct(int type)
{
	static t_var	variables;
	static t_arg	args;

	if (type == 0)
		return (&variables);
	if (type == 1)
		return (&args);
	return (NULL);
}
