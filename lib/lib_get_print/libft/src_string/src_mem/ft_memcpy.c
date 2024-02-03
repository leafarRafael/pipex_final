/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:43:02 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/10 17:15:46 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*des;
	unsigned char	*sr;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	des = (unsigned char *) dest;
	sr = (unsigned char *) src;
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
	return (dest);
}
