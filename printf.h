/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruislayer <ruislayer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:28:15 by rucosta           #+#    #+#             */
/*   Updated: 2025/05/13 18:59:00 by ruislayer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			put_pointer(void *ptr);
int			put_hex(unsigned int n, int uppercase);
int			put_unsigned(unsigned int n);
int			put_int(int n);
int			ft_printf(const char *ptr, ...);
#endif