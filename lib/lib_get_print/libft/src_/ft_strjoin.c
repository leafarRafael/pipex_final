/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:11:11 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/05 17:34:51 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	size_s1;
	size_t	size_s2;
	size_t	size;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	size = size_s1 + size_s2 +1;
	new_str = ft_calloc (sizeof(char), size);
	if (!new_str)
		return (NULL);
	if (size < 2)
		return (new_str);
	else
	{
		ft_memcpy(new_str, s1, size_s1);
		ft_strlcpy(&new_str[size_s1], s2, size_s2 + 1);
	}
	return (new_str);
}
