/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:31:40 by rbutzke           #+#    #+#             */
/*   Updated: 2023/11/03 15:08:11 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	diff;

	i = 0;
	diff = 0;
	while (i < n && (s1[i] != '\0' && s1[i] != '\0'))
	{
		diff = (unsigned char )s1[i] - (unsigned char )s2[i];
		if (diff != 0)
			break ;
		i++;
	}
	if (i < n)
		return ((unsigned char )s1[i] - (unsigned char )s2[i]);
	return (diff);
}
