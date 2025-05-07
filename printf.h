/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rucosta <rucosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:28:15 by rucosta           #+#    #+#             */
/*   Updated: 2025/05/07 22:37:14 by rucosta          ###   ########.fr       */
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

void		put_pointer(void *ptr);
void		put_hex(unsigned int n, int uppercase);
void		put_unsigned(unsigned int n);
void		put_int(int n);
static char	is_in_set(const char *ptr, int pos);
static void	print_var(char c, va_list args);
int			ft_printf(const char *ptr, ...);
#endif