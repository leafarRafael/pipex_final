/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:11:11 by rbutzke           #+#    #+#             */
/*   Updated: 2023/11/03 15:07:47 by rbutzke          ###   ########.fr       */
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
	new_str = malloc (sizeof(char) * size);
	if (new_str == NULL)
		return (NULL);
	if (size < 2)
		new_str[0] = '\0';
	else
	{
		ft_memcpy(new_str, s1, size_s1);
		ft_strlcpy(&new_str[size_s1], s2, size_s2 + 1);
	}
	return (new_str);
}
