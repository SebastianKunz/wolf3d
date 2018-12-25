/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:23:40 by skunz             #+#    #+#             */
/*   Updated: 2018/10/05 19:23:43 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(t_list *lst)
{
	t_list *temp;

	while (lst)
	{
		temp = lst;
		free(lst);
		lst = temp->next;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *begin;

	if (!lst || !f)
		return (NULL);
	if (!(result = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	result = f(result);
	lst = lst->next;
	begin = result;
	while (lst)
	{
		if (!(result->next = ft_lstnew(lst->content, lst->content_size)))
		{
			ft_freeall(begin);
			return (NULL);
		}
		result->next = f(result->next);
		result = result->next;
		lst = lst->next;
	}
	return (begin);
}
