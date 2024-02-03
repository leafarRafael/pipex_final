/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:55:46 by rbutzke           #+#    #+#             */
/*   Updated: 2023/11/03 15:08:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (len < 0)
		len = ft_strlen(little);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[y])
		{
			if (y == ft_strlen(little) - 1)
				return ((char *)&big[i - y]);
			y++;
		}
		else
		{
			i -= y;
			y = 0;
		}
		i++;
	}
	return (NULL);
}
