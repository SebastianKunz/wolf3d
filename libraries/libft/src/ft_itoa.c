/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 18:32:23 by skunz             #+#    #+#             */
/*   Updated: 2018/09/23 18:32:24 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	short	sign;
	long	l;

	sign = 0;
	l = n;
	len = ft_intlen(n);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (l < 0)
	{
		sign = 1;
		l *= -1;
	}
	while (len--)
	{
		res[len] = l % 10 + '0';
		l /= 10;
	}
	if (sign)
		res[0] = '-';
	return (res);
}
