/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:09:35 by skunz             #+#    #+#             */
/*   Updated: 2018/09/19 18:09:38 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *begin;

	begin = dest;
	while (n--)
	{
		if (!*src)
			*dest = '\0';
		else
		{
			*dest = *src;
			src++;
		}
		dest++;
	}
	return (begin);
}
