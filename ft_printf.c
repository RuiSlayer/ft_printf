/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:38:36 by rucosta           #+#    #+#             */
/*   Updated: 2025/05/07 22:35:18 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	is_in_set(const char *ptr, int pos)
{
	char	*set;

	set = "cspdiuxX%";
	if (ft_strrchr(set, ptr[pos]))
		return (ptr[pos]);
	return (0);
}

static void	print_var(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		put_pointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		put_int(va_arg(args, int));
	else if (c == 'u')
		put_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		put_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		put_hex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		i;
	char	c;

	i = 0;
	va_start(args, ptr);
	while (ptr[i])
	{
		if (ptr[i - 1] == '%')
		{
			c = is_in_set(ptr, i + 1);
			if (c)
			{
				print_var(c, args);
				i += 2;
				continue ;
			}
		}
		ft_putchar(ptr[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}
