/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:09:43 by skunz             #+#    #+#             */
/*   Updated: 2018/09/19 18:09:45 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	len++;
	while (len--)
	{
		if (*s == c)
			return ((char*)s);
		s--;
	}
	return (NULL);
}
