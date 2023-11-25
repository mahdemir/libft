/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_printing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 23:51:04 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 15:36:22 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_print_char(int c)
{
	return (write(1, &c, 1));
}

int	pf_print_str(char *str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (*str)
		count += write(1, str++, 1);
	return (count);
}

int	pf_print_pointer(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (pf_putnbr_base((unsigned long)ptr, "0123456789abcdef") + 2);
}

int	pf_print_int(long num)
{
	if (num < 0)
	{
		pf_print_char('-');
		return (pf_putnbr_base(-num, "0123456789") + 1);
	}
	else
		return (pf_putnbr_base(num, "0123456789"));
}

int	pf_print_uint_hex(unsigned int num, char letter)
{
	if (letter == 'u')
		return (pf_putnbr_base(num, "0123456789"));
	if (letter == 'x')
		return (pf_putnbr_base(num, "0123456789abcdef"));
	else
		return (pf_putnbr_base(num, "0123456789ABCDEF"));
}
