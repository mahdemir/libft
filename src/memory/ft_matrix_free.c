/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix_free.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/28 12:29:26 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/21 16:45:59 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_free(void **arr)
{
	int	height;

	height = 0;
	while (arr[height])
		height++;
	while (height--)
		free(arr[height]);
	free(arr);
}
