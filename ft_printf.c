/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruislayer <ruislayer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:38:36 by rucosta           #+#    #+#             */
/*   Updated: 2025/05/12 21:04:13 by ruislayer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
		if (ptr[i] == '%' && ptr[i + 1])
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

int main(void)
{
    int ret_std, ret_ft;
    char *str = "world";
    int num = 42;
    unsigned int u = 3000000000;
    void *ptr = str;

    // Test 1: Characters
    ret_std = printf("1. Std: Hello %c\n", 'A');
    ret_ft = ft_printf("1. Ft : Hello %c\n", 'A');
    printf("Return - Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    // Test 2: Strings
    ret_std = printf("2. Std: Hello %s\n", str);
    ret_ft = ft_printf("2. Ft : Hello %s\n", str);
    printf("Return - Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    // Test 3: Pointers
    ret_std = printf("3. Std: Pointer %p\n", ptr);
    ret_ft = ft_printf("3. Ft : Pointer %p\n", ptr);
    printf("Return - Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    // Test 4: Decimal and Integer
    ret_std = printf("4. Std: Number %d and %i\n", num, -num);
    ret_ft = ft_printf("4. Ft : Number %d and %i\n", num, -num);
    printf("Return - Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    // Test 5: Unsigned
    ret_std = printf("5. Std: Unsigned %u\n", u);
    ret_ft = ft_printf("5. Ft : Unsigned %u\n", u);
    printf("Return - Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    // Test 6: Hex lowercase
    ret_std = printf("6. Std: Hex lowercase %x\n", 305441741);
    ret_ft = ft_printf("6. Ft : Hex lowercase %x\n", 305441741);
    printf("Return - Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    // Test 7: Hex uppercase
    ret_std = printf("7. Std: Hex uppercase %X\n", 305441741);
    ret_ft = ft_printf("7. Ft : Hex uppercase %X\n", 305441741);
    printf("Return - Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    // Test 8: Percent sign
    ret_std = printf("8. Std: Show 100%% success\n");
    ret_ft = ft_printf("8. Ft : Show 100%% success\n");
    printf("Return - Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    // Test 9: NULL string
    ret_std = printf("9. Std: Null string: %s\n", (char *)NULL);
    ret_ft = ft_printf("9. Ft : Null string: %s\n", (char *)NULL);
    printf("Return - Std: %d | Ft: %d\n\n", ret_std, ret_ft);

    return 0;
}
