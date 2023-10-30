/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:03:29 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 13:44:38 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(s))
	{
		if (*(s) == (char)c)
			return ((char *)s);
		s++;
	}
	if (*(s) == (char)c)
		return ((char *)s);
	return (NULL);
}
