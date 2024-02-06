/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_other_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 09:47:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/06 10:49:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_size_matrix(char *str, char c_to_count, char delimiter)
{
	int	index;
    int	is_limiter;
    int	is_character_to_count;

    is_character_to_count = 1;
    is_limiter = 0;
    index = 0;
    while (str[index] == c_to_count)
        index++;
    while (str[index] != '\0')
    {
        if (str[index] == delimiter)
            is_limiter++;
        if (is_limiter % 2 == 0)
            if (str[index] == c_to_count && str[index +1] != c_to_count && str[index +1] != '\0')
                is_character_to_count++;
        index++;
    }
    ft_putnbr_fd(is_character_to_count, 2);
    return (is_character_to_count);
}

int	ft_strlen_ch(char *str, char stop_if, char ignore_if)
{
    int i;
    int ignore;

    ignore = 1;
    i = 0;
    while (str[i] == ' ')
        i++;
    while (str[i] != '\0')
    {
        if (str[i] == ignore_if)
        {
            i++;
            if (str[i] == '\0')
                return (++i);
            ignore++;
        }
        if (ignore % 2 == 0)            
            if (str[i] == ignore_if)
                ignore++;
        if (ignore % 2 != 0)
            if (str[i] == stop_if)
                return (++i);
        i++;
    }
    return (++i);
}