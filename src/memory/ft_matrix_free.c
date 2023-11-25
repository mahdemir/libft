/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix_free.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/28 12:29:26 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/25 13:32:21 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_free(void **matrix, int height)
{
	while (height--)
		free(matrix[height]);
	free(matrix);
}
