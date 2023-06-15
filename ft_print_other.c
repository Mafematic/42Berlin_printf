/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:53:50 by fszendzi          #+#    #+#             */
/*   Updated: 2023/06/15 16:53:52 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	else
		return (1);
}

int	ft_putstr(const char *str)
{
	int	i;
	int	ret;

	if (!str)
	{
		ret = ft_putstr("(null)");
		if (ret == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		ret = write(1, &str[i], 1);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long long int n)
{
	char	hex_digits[17];
	char	hex[17];
	int		i;
	int		final;

	ft_strcpy(hex_digits, "0123456789abcdef");
	i = 0;
	if (n == 0)
	{
		return (ft_putchar('0'));
	}
	while (n != 0)
	{
		hex[i++] = hex_digits[n % 16];
		n /= 16;
	}
	final = i;
	while (i-- > 0)
	{
		if (ft_putchar(hex[i]) == -1)
			return (-1);
	}
	return (final);
}

int	ft_puthex_large(unsigned long long int n)
{
	char	hex_digits[17];
	char	hex[17];
	int		i;
	int		final;

	ft_strcpy(hex_digits, "0123456789ABCDEF");
	i = 0;
	if (n == 0)
	{
		return (ft_putchar('0'));
	}
	while (n != 0)
	{
		hex[i++] = hex_digits[n % 16];
		n /= 16;
	}
	final = i;
	while (i-- > 0)
	{
		if (ft_putchar(hex[i]) == -1)
			return (-1);
	}
	return (final);
}

int	ft_putptr(void *ptr)
{
	int						ret;
	unsigned long long int	addr;

	if (ptr == NULL)
	{
		ret = write(1, "(nil)", 5);
		if (ret == -1)
			return (-1);
		return (5);
	}
	else
	{
		addr = (unsigned long long int)ptr;
		ret = write(1, "0x", 2);
		if (ret == -1)
			return (-1);
		ret = ft_puthex(addr);
		if (ret == -1)
			return (-1);
		return (2 + ret);
	}
}

/* MAC
	if (ptr == NULL)
	{
		ret = write(1, "0x0", 3);
		if (ret == -1)
			return (-1);
		return (3);
	}
	*/
