/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:03:02 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 13:44:32 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*ptr;

	num = n;
	len = ft_nbrlen(num);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (num == 0)
		ptr[0] = '0';
	else if (num < 0)
		ptr[0] = '-';
	while (num)
	{
		if (num < 0)
			ptr[--len] = ((num * -1) % 10) + 48;
		else
			ptr[--len] = (num % 10) + 48;
		num /= 10;
	}
	return (ptr);
}
