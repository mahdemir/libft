/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:03:56 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 13:45:19 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = (char *)&s[len - 1];
	while (len--)
	{
		if (*(ptr--) == (char)c)
			return (++ptr);
	}
	return (NULL);
}
