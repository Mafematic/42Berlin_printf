#include "ft_printf.h"

int ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

int ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(const char *str)
{
	int i; 

	i = 0; 
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++; 
	}
	return 1; 
}

int ft_putnbr(int n)
{
	long num;

	num = n; 
	if (num < 0)
	{
		write(1, "-1", 1);
		num = -num; 
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar(num % 10 + '0');
	return 1; 
}

int ft_puthex(unsigned long long int n)
{
	char hex_digits[] = "0123456789abcdef";
	char hex[9]; 

	int i = 0;
	int remainder;
	if (n == 0)
	{
		write(1, "0", 1);
		return 1;
	}

	while (n != 0)
	{
		remainder = n % 16; 
		hex[i] = hex_digits[remainder];
		n /= 16; 
		i++; 
	}
	int final = i;  
	while (i > 0)
	{
		i--;
		write(1, &hex[i], 1);
	}
	return final;
}

int ft_puthex_large(unsigned long long int n)
{
	char hex_digits[] = "0123456789ABCDEF";
	char hex[9];

	int i = 0;
	int remainder;
	if (n == 0)
	{
		write(1, "0", 1);
		return 1;
	}

	while (n != 0)
	{
		remainder = n % 16;
		hex[i] = hex_digits[remainder];
		n /= 16;
		i++;
	}
	int final = i;
	while (i > 0)
	{
		i--;
		write(1, &hex[i], 1);
	}
	return final;
}

int ft_putptr(void *ptr)
{
	unsigned long long int addr = (unsigned long long int)ptr;
	write(1, "0x", 2);
	return (2 + ft_puthex(addr));
}
