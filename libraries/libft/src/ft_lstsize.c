/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:04:41 by skunz             #+#    #+#             */
/*   Updated: 2018/10/07 20:04:42 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *begin_list)
{
	size_t len;

	len = 0;
	if (!begin_list)
		return (0);
	while (begin_list)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
}
