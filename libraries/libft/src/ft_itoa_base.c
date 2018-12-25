/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:06 by skunz             #+#    #+#             */
/*   Updated: 2018/12/06 18:22:07 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long n, int base)
{
	char		*res;
	int			len;
	short		sign;
	long long	temp;

	sign = (n < 0) ? 1 : 0;
	len = 0;
	temp = (n < 0) ? -n : n;
	sign ? len++ : 0;
	while ((temp /= base) > 0)
		len++;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	n = (n < 0) ? -n : n;
	while (len--)
	{
		if (n % base < 10)
			res[len] = n % base + '0';
		else
			res[len] = n % base + 'A' - 10;
		n /= base;
	}
	(sign) ? res[0] = '-' : 0;
	return (res);
}
