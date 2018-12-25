/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:07:25 by skunz             #+#    #+#             */
/*   Updated: 2018/09/19 18:07:26 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*psrc;
	char	*pdest;
	size_t	i;

	psrc = (char*)src;
	pdest = (char *)dest;
	i = -1;
	if (src < dest)
		while (n--)
			*(pdest + n) = *(psrc + n);
	else
		while (++i < n)
			*(pdest + i) = *(psrc + i);
	return (dest);
}
