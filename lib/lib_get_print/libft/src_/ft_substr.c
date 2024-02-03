/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:49:44 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/02 09:47:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	char	*array;
	size_t	new_len;

	new_len = 0;
	size_s = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= size_s)
	{
		array = malloc(sizeof(char) * 1);
		if (array == NULL)
			return (NULL);
		array[0] = '\0';
	}
	else
	{
		if (len >= size_s)
			len = ft_strlen(&s[start]);
		array = malloc(sizeof(char) * (len + 1));
		if (array == NULL)
			return (NULL);
		ft_strlcpy(array, &s[start], len + 1);
	}
	return (array);
}
