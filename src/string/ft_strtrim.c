/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:03:59 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 13:45:22 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup("\0"));
	begin = 0;
	end = ft_strlen(s1) - 1;
	while (*(s1 + begin) && ft_strchr(set, *(s1 + begin)))
		++begin;
	while (end >= 0 && ft_strchr(set, *(s1 + end)))
		--end;
	if (begin > end)
		return (ft_strdup(""));
	str = malloc((end - begin) + 2);
	if (NULL == str)
		return (NULL);
	ft_strlcpy(str, s1 + begin, (end - begin) + 2);
	return (str);
}
