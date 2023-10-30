/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 23:16:41 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 16:12:02 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

// Mimic of original printf that supports: c s i d p u x X %
int	ft_printf(const char *format, ...);

/* Functions to write chartaters and digits for specific formats
** Returns total length written. */
int	pf_print_char(int c);
int	pf_print_str(char *str);
int	pf_print_pointer(void *ptr);
int	pf_print_int(long num);
int	pf_print_uint_hex(unsigned int num, char letter);

/* Outputs a integer using a base to standard output.
** Returns total length written. */
int	pf_putnbr_base(unsigned long nb, char *base);

// Returns the length of the string s.
int	pf_strlen(char *str);

#endif
