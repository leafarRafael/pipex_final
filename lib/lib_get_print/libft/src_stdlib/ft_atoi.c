/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:10:31 by rbutzke           #+#    #+#             */
/*   Updated: 2023/11/03 15:05:08 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(const char c)
{
	return (c == ' ' || c == '\n'
		|| c == '\f' || c == '\r'
		|| c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	is_negative;

	is_negative = 0;
	nbr = 0;
	i = 0;
	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_negative++;
		i++;
	}
	while (ft_isdigit(nptr[i]) > 0)
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		if (ft_isdigit(nptr[i]) == 0)
			break ;
		i++;
	}
	if (is_negative > 0)
		nbr = -nbr;
	return (nbr);
}
