/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:37:34 by rbutzke           #+#    #+#             */
/*   Updated: 2023/12/16 10:30:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef H_BASE_UP
#  define H_BASE_UP "0123456789ABCDEF"
# endif

# ifndef H_BASE_LW
#  define H_BASE_LW "0123456789abcdef"
# endif

# ifndef DEC_BASE
#  define DEC_BASE "0123456789"
# endif

void	ft_select_function(char c, va_list *args, int *l);
int		ft_putpointer(unsigned long long n, char *base);
int		ft_putnbr_base(long int n, char *base);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_strl(char *s);
int		ft_putstr(char *s);

#endif