#include "ft_printf.h"

int	print_number_string_unsigned(unsigned long num)
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

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned long	num;
	int				count;

	num = n;
	count = print_number_string_unsigned(num);
	if (count == -1)
		return (-1);
	return (count);
}
