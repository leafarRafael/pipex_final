/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:27:10 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/10 17:15:54 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*y;
	unsigned char	add;
	size_t			i;

	y = (unsigned char *) s;
	add = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		y[i] = add;
		i++;
	}
	return (s);
}
