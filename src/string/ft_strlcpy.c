/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:03:42 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 13:45:00 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		len;

	len = ft_strlen(src);
	if (!src || !dst || !dstsize)
		return (len);
	while (*src && --dstsize)
		*(dst++) = *(src++);
	*(dst) = '\0';
	return (len);
}
