/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix_free_h.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 07:55:55 by mademir       #+#    #+#                 */
/*   Updated: 2023/12/30 08:39:22 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_free_h(void **matrix, int height)
{
	while (height--)
		free(matrix[height]);
	free(matrix);
}
