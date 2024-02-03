/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:36:11 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/07 14:42:41 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_select_function(char c, va_list *args, int *l)
{
	if (c == 'c')
		(*l) += ft_putchar(va_arg(*args, int));
	else if (c == '%')
		(*l) += ft_putchar('%');
	else if (c == 's')
		(*l) += ft_putstr(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
		(*l) += ft_putnbr_base(va_arg(*args, int), DEC_BASE);
	else if (c == 'x')
		(*l) += ft_putnbr_base(va_arg(*args, unsigned int), H_BASE_LW);
	else if (c == 'X')
		(*l) += ft_putnbr_base(va_arg(*args, unsigned int), H_BASE_UP);
	else if (c == 'u')
		(*l) += ft_putnbr_base(va_arg(*args, unsigned int), DEC_BASE);
	else if (c == 'p')
		(*l) += ft_putpointer(va_arg(*args, unsigned long long), H_BASE_LW);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		length;

	va_start(args, str);
	length = 0;
	index = 0;
	if (str == NULL)
		return (-1);
	while (str[index])
	{
		if (str[index] == '%')
		{
			ft_select_function(str[index +1], &args, &length);
			index++;
		}
		else
			length += ft_putchar(str[index]);
		index++;
	}
	va_end(args);
	return (length);
}
