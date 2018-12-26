/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 19:46:29 by skunz             #+#    #+#             */
/*   Updated: 2018/12/25 19:46:30 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void const *content,
	size_t content_size)
{
	t_list *list;

	if (*begin_list)
	{
		list = ft_lstnew(content, content_size);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_lstnew(content, content_size);
}
