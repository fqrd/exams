#include "ft_printf.h"


#include <stdarg.h>
#include <unistd.h>

size_t	ft_putchar(unsigned char c)
{
	return ((size_t)write(1, &c, 1));
}

void	ft_putstr(char *str, size_t *count)
{
	size_t i = 0;
	if (!str)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
		i++;
	*count += write(1, str, i);
}


void	print_x(unsigned int x, char *base, size_t *count)
{
	if (x < 16)
	{
		*count += ft_putchar(base[x]);
	}
	else
	{
		print_x(x/16, base, count);
		*count += ft_putchar(base[x % 16]);
	}
}

void	print_d(int d, size_t *count)
{
	if (d > -10 && d < 10)
	{
		if (d < 0)
		{
			*count += write(1, "-", 1);
			d = d * (-1);
		}
		*count += ft_putchar(d + '0');
	}
	else
	{
		print_d(d/10, count);
		if (d < 0)
		{
			*count += ft_putchar(((d % 10) * (-1)) + '0');
		}
		else
		{
			*count += ft_putchar((d % 10) + '0');
		}
	}
}


void	fn_switch(va_list args, char format, size_t *count)
{
	if (format == 's')
	{
		ft_putstr(va_arg(args, char *), count);
	}
	if (format == 'd')
	{
		print_d(va_arg(args, int), count);
	}
	if (format == 'x')
	{
		print_x(va_arg(args, unsigned int), "0123456789abcdef",count);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	size_t count = 0;
	size_t i = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			count += write(1, &format[i], 1);
			i++;
		}
		else
		{
			if (format[++i])
			{
				fn_switch(args, format[i], &count);
				i++;
			}
		}
	}
	va_end(args);
	return (count);
}
