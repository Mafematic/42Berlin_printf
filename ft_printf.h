#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *, ...);
int ft_putchar(int c);
int ft_putstr(const char *str);
int ft_putnbr(int n);
int ft_puthex(unsigned long long int n);
int ft_puthex_large(unsigned long long int n);
int ft_putptr(void *ptr);
int ft_isalpha(int c);

#endif 