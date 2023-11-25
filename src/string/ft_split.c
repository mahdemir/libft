/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 14:39:21 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/25 14:48:09 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static void	fill_arr(char **matrix, const char *s, char c)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (*(s + i))
	{
		len = 0;
		while (*(s + i) == c)
			i++;
		while (*(s + i) != c && *(s + i))
		{
			i++;
			len++;
		}
		if (len)
			matrix[j] = malloc(len + 1);
		if (!matrix[j])
			matrix[j] = NULL;
		ft_strlcpy(matrix[j++], s + (i - len), len + 1);
	}
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		words;
	char	**matrix;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	matrix = malloc((words + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix[words] = NULL;
	fill_arr(matrix, s, c);
	j = 0;
	while (j < words)
	{
		if (!matrix[j])
			ft_matrix_free((void **)matrix, words);
		j++;
	}
	return (matrix);
}
