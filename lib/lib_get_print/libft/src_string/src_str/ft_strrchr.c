/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:22:43 by rbutzke           #+#    #+#             */
/*   Updated: 2023/11/03 15:08:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	int				i;
	int				size;
	char			*z;

	i = ft_strlen(s);
	ch = (unsigned char) c;
	z = (char *) s;
	if (ch < 0 || ch > 255)
		return (NULL);
	if (ch == '\0')
	{
		size = ft_strlen(s);
		return (&z[size]);
	}
	while (i >= 0)
	{
		if (z[i] == ch)
		{
			return (&z[i]);
			break ;
		}
		i--;
	}
	return (NULL);
}
