/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruislayer <ruislayer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:38:36 by rucosta           #+#    #+#             */
/*   Updated: 2025/05/14 22:58:23 by ruislayer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	print_var(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (put_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (put_int(va_arg(args, int)));
	else if (c == 'u')
		return (put_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (put_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (put_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += print_var(format[i + 1], args);
			i += 2;
			continue ;
		}
		count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
