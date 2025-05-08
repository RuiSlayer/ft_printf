/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:38:36 by rucosta           #+#    #+#             */
/*   Updated: 2025/05/08 20:26:56 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	print_var(char c, va_list args)
{
	if (c == 'c')
		return(ft_putchar((char)va_arg(args, int)));
	else if (c == 's')
		return(ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return(put_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return(put_int(va_arg(args, int)));
	else if (c == 'u')
		return(put_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return(put_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return(put_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return(ft_putchar('%'));
	else
		return(ft_putchar(c));
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, ptr);
	while (ptr[i])
	{
		if (ptr[i] == '%')
		{
			count += print_var(ptr[i + 1], args);
			i += 2;
			continue ;
		}
		count += ft_putchar(ptr[i]);
		i++;
	}
	va_end(args);
	return (count);
}
