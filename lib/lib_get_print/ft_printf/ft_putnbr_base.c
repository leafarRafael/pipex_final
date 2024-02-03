/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:39:16 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/16 10:31:04 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_nbr(long n, int base)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / base;
	}
	return (size);
}

static void	ft_nbr_negative(long int *n, int *index_l, char **c_nbr)
{
	if ((*n) < 0)
	{
		(*c_nbr)[(*index_l)] = '-';
		(*n) = -(*n);
		(*index_l)++;
	}
}

int	ft_putnbr_base(long int n, char *base)
{
	int					index_l;
	int					size_nbr;
	int					size_base;
	int					length_str;
	char				*c_nbr;

	size_base = ft_strl(base);
	size_nbr = ft_size_nbr(n, size_base);
	index_l = 0;
	c_nbr = malloc (sizeof(char) * (size_nbr +1));
	if (!c_nbr)
		return (0);
	ft_nbr_negative(&n, &index_l, &c_nbr);
	c_nbr[size_nbr] = '\0';
	while (size_nbr != index_l)
	{
		size_nbr--;
		c_nbr[size_nbr] = base[n % size_base];
		n = n / size_base;
	}
	length_str = ft_putstr(c_nbr);
	free(c_nbr);
	return (length_str);
}
