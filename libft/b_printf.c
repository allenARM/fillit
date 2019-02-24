/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:38:24 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/19 09:40:49 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static void		conversions(char c, va_list arg)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int));
	if (c == 'd')
		ft_putnbr(va_arg(arg, int));
	if (c == 'i')
		ft_putnbr(va_arg(arg, int));
	if (c == 'o')
		ft_putstr(ft_itoa_base(va_arg(arg, unsigned int), 8));
	if (c == 'p')
	{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base(va_arg(arg, long long int), 16));
	}
	if (c == 's')
		ft_putstr(va_arg(arg, char *));
	if (c == 'u')
		ft_putunsignedint(va_arg(arg, unsigned int));
	if (c == 'x')
		ft_putstr(ft_itoa_base(va_arg(arg, unsigned int), 16));
	if (c == '%')
		ft_putchar('%');
}

int				b_printf(const char *restrict format, ...)
{
	int			i;
	va_list		arg;

	i = 0;
	g_count = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		while (format[i] != '\0' & format[i] != '%')
			ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			++i;
			while (format[i] == ' ')
				++i;
			if (format[i] == '\0')
				return (g_count);
			conversions(format[i++], arg);
		}
	}
	va_end(arg);
	return (g_count);
}
