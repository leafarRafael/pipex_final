/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:54:58 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/10 17:15:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	size_t				i;
	size_t				diff;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	diff = 0;
	if (n <= 0)
		return (diff);
	while (i < n)
	{
		diff = (*str1++) - (*str2++);
		if (diff != 0)
			break ;
		i++;
	}
	return (diff);
}
