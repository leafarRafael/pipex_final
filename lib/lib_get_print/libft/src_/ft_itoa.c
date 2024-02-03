/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:24:13 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/10 17:15:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length_int(int n)
{
	int			size;
	long int	nb;

	nb = (long) n;
	size = 0;
	if (n <= 0)
		size++;
	while (nb != 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

static void	ft_nbr(int size, int j, char *nbr, long int *nb)
{
	while (size >= j)
	{
		nbr[size] = (*nb % 10) + '0';
		*nb = *nb / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			size;
	long int	nb;
	int			j;

	nb = (long)n;
	size = ft_length_int(n);
	nbr = ft_calloc(sizeof(char), size +1);
	if (nbr == NULL)
		return (NULL);
	j = 0;
	if (n < 0)
	{
		nbr[j] = '-';
		nb = -nb;
		j++;
	}
	ft_nbr(size -1, j, nbr, &nb);
	return (nbr);
}
