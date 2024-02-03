/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:29:48 by rbutzke           #+#    #+#             */
/*   Updated: 2023/11/03 15:08:20 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ask_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_array;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) -1;
	while (ft_ask_set(set, s1[start]) == 1)
		start++;
	if (start >= end)
	{
		new_array = ft_calloc (1, 1);
		if (new_array == NULL)
			return (NULL);
		new_array[0] = '\0';
		return (new_array);
	}
	while (ft_ask_set(set, s1[end]) == 1)
		end--;
	new_array = ft_calloc(sizeof(char), ((end - start) + 2));
	if (new_array == NULL)
		return (NULL);
	ft_strlcpy(new_array, &s1[start], ((end - start) + 2));
	return (new_array);
}
