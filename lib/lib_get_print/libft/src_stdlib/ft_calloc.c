/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:29:33 by rbutzke           #+#    #+#             */
/*   Updated: 2024/01/02 09:41:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (size <= 0 && nmemb <= 0)
	{
		size = 1;
		nmemb = 1;
	}
	array = malloc(size * nmemb);
	if (!array)
		return (NULL);
	ft_bzero(array, size * nmemb);
	return (array);
}
