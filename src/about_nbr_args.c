/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_nbr_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:40:38 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/04 09:37:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_valid_nbr_args(int argc)
{
	if (argc > 5)
	{
		ft_putstr_fd("Check the number of arguments", 2);
		exit(EXIT_FAILURE);
	}
}