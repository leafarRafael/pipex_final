/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:55:58 by rbutzke           #+#    #+#             */
/*   Updated: 2023/11/03 15:32:20 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*h;

	if (del == NULL && lst == NULL)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		h = *lst;
		*lst = h->next;
		free(h);
	}
	*lst = NULL;
}
