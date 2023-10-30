/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/28 17:34:18 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 18:05:48 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(const char *big, const char *little)
{
	char	*last;
	char	*found;

	if (!big)
		return (NULL);
	if (!*little)
		return ((char *)big);
	found = ft_strstr(big, little);
	while (found)
	{
		last = found;
		found = ft_strstr(found + 1, little);
	}
	return (last);
}
