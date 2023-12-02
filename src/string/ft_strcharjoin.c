/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcharjoin.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/02 15:23:33 by mademir       #+#    #+#                 */
/*   Updated: 2023/12/02 15:33:21 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcharjoin(char *s1, char c)
{
	int		i;
	size_t	len;
	char	*ptr;

	if (!s1 || !c)
		return (0);
	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = c;
	i++;
	*(ptr + i) = '\0';
	free(s1);
	return (ptr);
}
