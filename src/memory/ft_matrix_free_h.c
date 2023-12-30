/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix_free_h.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 07:55:55 by mademir       #+#    #+#                 */
/*   Updated: 2023/12/30 07:56:28 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_matrix_free_h(void **matrix, int height)
{
	while (height--)
		free(matrix[height]);
	free(matrix);
}
