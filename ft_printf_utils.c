#include "ft_printf.h"
#include <stdio.h>

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

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}

	i = 0; 
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++; 
	}
	return i; 
}

int ft_putnbr(int n)
{
    int count = 0;
    long num = n;
    char *arr;
    int i;

    i = 0;
    if (num < 0)
    {
        num = -num;
    }

    if (num == 0)
        count++;

    long tmp_num = num; 
    while (tmp_num >= 1)
    {
        count++;
        tmp_num /= 10;
    }

    arr = (char*)malloc(sizeof(char) * (count + 1));
    arr[count] = '\0'; 

    if (n == 0)
        arr[0] = '0';
    else
    {
        while (i < count)
        {
            arr[count - i - 1] = num % 10 + '0';
            num /= 10;
            i++;
        }
    }

    if (n < 0)
    {
        write(1, "-", 1);
    }
    write(1, arr, count);

    free(arr);

    if(n < 0)
	{
    	return count + 1;
	}
	else
	{
    	return count;
	}
}

int ft_putnbr_unsigned(unsigned int n)
{
    int count = 0;
    unsigned long num = n;
    char *arr;
    int i;

    i = 0;

    if (num == 0)
        count++;

    unsigned long tmp_num = num; 
    while (tmp_num >= 1)
    {
        count++;
        tmp_num /= 10;
    }

    arr = (char*)malloc(sizeof(char) * (count + 1));
    arr[count] = '\0'; 

    if (n == 0)
        arr[0] = '0';
    else
    {
        while (i < count)
        {
            arr[count - i - 1] = num % 10 + '0';
            num /= 10;
            i++;
        }
    }

    write(1, arr, count);

    free(arr);

    return count;
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
	if (ptr == NULL)
    {
        write(1, "(nil)", 5);
        return 5;
    }
	else
	{
		unsigned long long int addr = (unsigned long long int)ptr;
		write(1, "0x", 2);
		return (2 + ft_puthex(addr));
	}
}
