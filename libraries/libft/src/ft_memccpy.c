/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:04:06 by skunz             #+#    #+#             */
/*   Updated: 2018/09/19 18:04:10 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*des;
	char const		*sr;

	des = dest;
	sr = src;
	while (n--)
	{
		*des++ = *sr;
		if ((unsigned char)*sr == (unsigned char)c)
			return (des);
		sr++;
	}
	return (NULL);
}
