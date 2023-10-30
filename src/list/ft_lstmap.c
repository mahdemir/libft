/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 14:54:42 by mademir       #+#    #+#                 */
/*   Updated: 2023/10/28 13:43:11 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst -> content));
	if (!new_lst)
		return (NULL);
	tmp = new_lst;
	lst = lst -> next;
	while (lst)
	{
		new_lst -> next = ft_lstnew(f(lst -> content));
		if (!new_lst -> next)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		new_lst = new_lst -> next;
		lst = lst -> next;
	}
	new_lst -> next = NULL;
	return (tmp);
}
