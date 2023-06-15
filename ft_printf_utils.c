#include "ft_printf.h"
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

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
	char hex_digits[] = "0123456789abcdef";
	char	hex[16];
	int		ret;
	int		i;
	int		remainder;
	int		final;

	i = 0;
	if (n == 0)
	{
		ret = ft_putchar('0');
		if (ret == -1)
		{
			return (-1);
		}
		return (1);
	}
	while (n != 0)
	{
		remainder = n % 16;
		hex[i] = hex_digits[remainder];
		n /= 16;
		i++;
	}
	final = i;
	while (i > 0)
	{
		i--;
		ret = ft_putchar(hex[i]);
		if (ret == -1)
		{
			return (-1);
		}
	}
	return (final);
}

int	ft_puthex_large(unsigned long long int n)
{
	char hex_digits[] = "0123456789ABCDEF";
	char	hex[16];
	int		ret;
	int		i;
	int		remainder;
	int		final;

	i = 0;
	if (n == 0)
	{
		ret = ft_putchar('0');
		if (ret == -1)
		{
			return (-1);
		}
		return 1;
	}
	while (n != 0)
	{
		remainder = n % 16;
		hex[i] = hex_digits[remainder];
		n /= 16;
		i++;
	}
	final = i;
	while (i > 0)
	{
		i--;
		ret = ft_putchar(hex[i]);
		if (ret == -1)
		{
			return -1;
		}
	}
	return final;
}

int	ft_putptr(void *ptr)
{
	int						ret;
	unsigned long long int	addr;

	// Linux
	/*if (ptr == NULL)
    {
        ret = write(1, "(nil)", 5);
        if (ret == -1)
            return -1;
        return 5;
    }*/
	// Mac
	if (ptr == NULL)
	{
		ret = write(1, "0x0", 3);
		if (ret == -1)
			return -1;
		return 3;
	}
	else
	{
		addr = (unsigned long long int)ptr;
		ret = write(1, "0x", 2);
		if (ret == -1)
			return -1;
		ret = ft_puthex(addr);
		if (ret == -1)
			return -1;
		return (2 + ret);
	}
}
