/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:23:56 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/10 18:49:41 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*new_array;
	unsigned int	size;

	size = ft_strlen(s) + 1;
	new_array = malloc(size * sizeof(char));
	if (!new_array)
		return (NULL);
	ft_strlcpy(new_array, s, size);
	return (new_array);
}
