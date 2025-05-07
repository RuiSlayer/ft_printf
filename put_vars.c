/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:15:35 by rucosta           #+#    #+#             */
/*   Updated: 2025/05/07 22:27:52 by rucosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	put_pointer(void *ptr)
{
	uintptr_t	address;
	char		buf[16];
	int			i;
	char		*base;

	address = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	if (address == 0)
	{
		ft_putchar_fd(0, 1);
		return ;
	}
	i = 0;
	base = "0123456789abcdef";
	while (address)
	{
		buf[i++] = base[address % 16];
		address /= 16;
	}
	while (i--)
		ft_putchar_fd(buf[i], 1);
}

void	put_hex(unsigned int n, int uppercase)
{
	char	*base;
	char	buf[8];
	int		i;

	i = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar_fd(buf[i], 1);
		return ;
	}
	while (n)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	while (i--)
		ft_putchar_fd(buf[i], 1);
}

void	put_unsigned(unsigned int n)
{
	char	buf[10];
	int		i;

	i = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	while (n)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		ft_putchar_fd(buf[i], 1);
}

void	put_int(int n)
{
	if (n < 0)
	{
		ft_put_char('-', 1);
		put_unsigned(-n);
		return ;
	}
	put_unsigned(n);
}
