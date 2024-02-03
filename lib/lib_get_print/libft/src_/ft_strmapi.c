/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:41:35 by rbutzke           #+#    #+#             */
/*   Updated: 2023/11/03 15:08:07 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_array;
	unsigned int	i;

	if (!s && !f)
		return (NULL);
	i = 0;
	if (ft_strlen(s) == 0)
	{
		new_array = malloc (sizeof(char) * 1);
		if (new_array == NULL)
			return (NULL);
		new_array[0] = '\0';
		return (new_array);
	}
	new_array = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (new_array == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new_array[i] = f(i, s[i]);
		i++;
	}
	new_array[i] = '\0';
	return (new_array);
}
