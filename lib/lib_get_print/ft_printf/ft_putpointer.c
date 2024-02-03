/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:39:16 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/16 10:31:14 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_nbr(unsigned long long n, int base)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		size++;
		n = n / base;
	}
	return (size);
}

int	ft_putpointer(unsigned long long n, char *base)
{
	int		size;
	int		lenght;
	int		size_base;
	char	*c_nbr;

	size_base = ft_strl(base);
	lenght = 0;
	if (n == 0)
		return (ft_putstr("(nil)"));
	size = ft_size_nbr(n, size_base);
	c_nbr = malloc (sizeof(char) * (size +1));
	if (!c_nbr)
		return (0);
	c_nbr[size] = '\0';
	while (size != 0)
	{
		size--;
		c_nbr[size] = base[n % size_base];
		n = n / size_base;
	}
	lenght += ft_putstr("0x");
	lenght += ft_putstr(c_nbr);
	free(c_nbr);
	return (lenght);
}
