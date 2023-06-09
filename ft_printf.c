/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:11:39 by fszendzi          #+#    #+#             */
/*   Updated: 2023/06/15 15:11:44 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_puthex(va_arg(args, unsigned int));
	else if (*format == 'X')
		count += ft_puthex_large(va_arg(args, unsigned int));
	else if (*format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_vprintf(const char *format, va_list args, int *count, int *ret)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_isalpha(format[i]) || format[i] == '%')
			{
				*ret = ft_parse_format(&format[i], args);
				if (*ret == -1)
					return (-1);
				*count += *ret;
				i++;
			}
		}
		else
		{
			if (ft_putchar(format[i++]) == -1)
				return (-1);
			(*count)++;
		}
	}
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	va_start(args, format);
	count = 0;
	ret = 0;
	count = ft_vprintf(format, args, &count, &ret);
	va_end(args);
	return (count);
}

/*
#include <stdio.h>
#include <limits.h>

int main(void)
{
	//char d = 'h';
	//printf("%%c");
	//printf("%%c");
	//printf(" %p %p ", 0, 0);
	// printf(" %d ", -1);
	// printf("%d", printf(" %d ", -1));
	// ft_printf("%d", ft_printf(" %d ", -1));

	//printf(" %d ", 10);
	//printf("%d", printf(" %d ", 0));
	//ft_printf("%d", ft_printf(" %d ", 0));

	//printf(" NULL %s NULL ", NULL);
	//printf("%d", printf(" NULL %s NULL ", NULL));

	//ft_printf("%s\n", NULL);
	//ft_printf(" NULL %s NULL ", NULL);
	//ft_printf("%d", ft_printf(" NULL %s NULL ", NULL));

	printf("%s", "--");
	printf("%d", printf("%s", "--"));
	ft_printf("%s", "--");
	ft_printf("%d", ft_printf("%s", "--"));


	char str[] = "Hello";
	int n = 255;
	void *ptr = &n;
	char c = 'A';

	printf("Test 1:\n");
	printf("printf: %s\n", str);
	ft_printf("ft_printf: %s\n", str);

	printf("\nTest 2:\n");
	printf("printf: %d\n", n);
	ft_printf("ft_printf: %d\n", n);

	printf("\nTest 3:\n");
	printf("printf: %x\n", n);
	ft_printf("ft_printf: %x\n", n);

	printf("\nTest 4:\n");
	printf("printf: %X\n", n);
	ft_printf("ft_printf: %X\n", n);

	printf("\nTest 5:\n");
	printf("printf: %p\n", ptr);
	ft_printf("ft_printf: %p\n", ptr);

	printf("\nTest 6:\n");
	printf("printf: %c\n", c);
	ft_printf("ft_printf: %c\n", c);

	printf("\nTest 7:\n");
	printf("printf: %%%c\n", c);
	ft_printf("ft_printf: %%%c\n", c);

	printf("\nTest 8:\n");
	printf("printf: %%\n");
	ft_printf("ft_printf: %%\n");

	printf("\nTest 9:\n");
	printf("printf: Hello\\nWorld\n");
	ft_printf("ft_printf: Hello\\nWorld\n");

	printf("\nTest 10:\n");
	printf("printf: \\tTabbed\\toutput\n");
	ft_printf("ft_printf: \\tTabbed\\toutput\n");

	printf("\nTest 11:\n");
	printf("printf: Multiple %s %d %c %x %X %p\n", str, n, c, n, n, ptr);
	ft_printf("ft_printf: Multiple %s %d %c %x %X %p\n", str, n, c, n, n, ptr);

	printf("\nTest 12:\n");
	printf("printf: Edge case: %d\n", INT_MAX);
	ft_printf("ft_printf: Edge case: %d\n", INT_MAX);

	printf("\nTest 13:\n");
	printf("printf: Edge case: %d\n", INT_MIN);
	ft_printf("ft_printf: Edge case: %d\n", INT_MIN);

	printf("\nBonus Tests\n");

	n = -42;

	printf("Test 1:\n");
	printf("printf: %+d\n", n);
	ft_printf("ft_printf: %+d\n", n);

	printf("\nTest 2:\n");
	printf("printf: %10s\n", str);
	ft_printf("ft_printf: %10s\n", str);

	printf("\nTest 3:\n");
	printf("printf: %08x\n", n);
	ft_printf("ft_printf: %08x\n", n);

	printf("\nTest 4:\n");
	printf("printf: %.4d\n", n);
	ft_printf("ft_printf: %.4d\n", n);

	printf("\nTest 5:\n");
	printf("printf: %6c\n", c);
	ft_printf("ft_printf: %6c\n", c);

	printf("\nTest 6:\n");
	printf("printf: %p\n", ptr);
	ft_printf("ft_printf: %p\n", ptr);

	printf("\nTest 7:\n");
	printf("printf: %.*s\n", 3, str);
	ft_printf("ft_printf: %.*s\n", 3, str);
	return 0;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_isalpha(format[i]) || format[i] == '%')
			{
				count += ft_parse(&format[i], args);
				i++;
			}
		}
		else
		{
			ft_putchar(format[i++]);
			count++;
		}
	}
	va_end(args);
	return count;
}
*/
