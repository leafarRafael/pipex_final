/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_other_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:47:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/04 11:22:25 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen_ch(char *str, char limiter)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!limiter || limiter == '\n')
		return (ft_strlen(str));
	while (str[i] != limiter)
		i++;
	return (i);
}

char	*ft_cp_even_my_limiter(char *str, char limiter)
{
	int		i;
	int		size;
	char	*new_str;

	size = ft_strlen_ch(str, limiter) +1;
	i = 0;
	if (!str || !limiter || size == 0)
		return (NULL);
	new_str = ft_calloc(sizeof(char), size +1);
	if (!new_str)
		return (NULL);
	while (str[i] != limiter && str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}