/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:07:20 by skunz             #+#    #+#             */
/*   Updated: 2018/09/19 18:07:22 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*res;
	size_t	i;

	res = dest;
	i = -1;
	while (++i < n)
	{
		res[i] = *(const char*)src;
		dest++;
		src++;
	}
	return (res);
}
