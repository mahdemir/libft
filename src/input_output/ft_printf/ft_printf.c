/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 23:13:45 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 16:12:47 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Outputs a character to standard output.
** Returns total length written. */
static int	pf_putchar(char c);

/* Function find what format to use.
** Returns total length written. */
static int	pf_print_format(char letter, va_list ap);

static int	pf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	pf_putnbr_base(unsigned long nb, char *base)
{
	unsigned long		len;
	int					count;

	count = 0;
	len = ft_strlen(base);
	if (nb >= len)
		count += pf_putnbr_base(nb / len, base);
	count += pf_putchar(base[nb % len]);
	return (count);
}

static int	pf_print_format(char letter, va_list ap)
{
	if (letter == 'c')
		return (pf_print_char(va_arg(ap, int)));
	if (letter == 's')
		return (pf_print_str(va_arg(ap, char *)));
	if (letter == 'i' || letter == 'd')
		return (pf_print_int(va_arg(ap, int)));
	if (letter == 'p')
		return (pf_print_pointer(va_arg(ap, void *)));
	if (letter == 'u')
		return (pf_print_uint_hex(va_arg(ap, unsigned int), letter));
	if (letter == 'x')
		return (pf_print_uint_hex(va_arg(ap, unsigned int), letter));
	if (letter == 'X')
		return (pf_print_uint_hex(va_arg(ap, unsigned int), letter));
	else
		return (write(1, &letter, 1));
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	if (!format)
		return (0);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && !*(format + 1))
			break ;
		else if (*format == '%')
			count += pf_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
