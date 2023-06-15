/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:12:39 by fszendzi          #+#    #+#             */
/*   Updated: 2023/06/15 15:12:41 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(long num)
{
	int	count;

	count = 0;
	if (num == 0)
		count++;
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

char	*allocate_string_memory(int size)
{
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	arr[size] = '\0';
	return (arr);
}

int	print_number_string(long num)
{
	int		count;
	char	*arr;
	int		i;
	int		ret;

	count = count_digits(num);
	arr = allocate_string_memory(count);
	if (!arr)
		return (-1);
	if (num == 0)
		arr[0] = '0';
	else
	{
		i = -1;
		while (++i < count)
		{
			arr[count - i - 1] = num % 10 + '0';
			num /= 10;
		}
	}
	ret = ft_putstr(arr);
	free(arr);
	if (ret == -1)
		return (-1);
	return (count);
}

int	ft_putnbr(int n)
{
	int		ret;
	long	num;
	int		count;

	num = n;
	if (num < 0)
	{
		num = -num;
		ret = ft_putchar('-');
		if (ret == -1)
		{
			return (-1);
		}
	}
	count = print_number_string(num);
	if (count == -1)
		return (-1);
	if (n < 0)
		return (count + 1);
	else
		return (count);
}
