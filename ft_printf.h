/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:12:21 by fszendzi          #+#    #+#             */
/*   Updated: 2023/06/15 15:12:26 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int 	ft_vprintf(const char *format, va_list args, int *count, int *ret, int *processed);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthex(unsigned long long int n);
int		ft_puthex_large(unsigned long long int n);
int		ft_putptr(void *ptr);
int		ft_isalpha(int c);
int		count_number_length(int n);
int		count_digits(long num);
char	*allocate_string_memory(int size);
int		print_number_string(long num);
int		print_number_string_unsigned(unsigned long num);
char	*ft_strcpy(char *dest, char *src);

#endif 
