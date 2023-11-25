/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix_height.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/19 14:57:15 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/25 13:44:17 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_matrix_height(void **matrix)
{
	size_t	height;

	height = 0;
	while (matrix[height])
		height++;
	return (height);
}
