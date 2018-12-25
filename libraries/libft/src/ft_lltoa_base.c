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
	len = 1;
	temp = (n < 0) ? -n : n;
	if (sign)
		len++;
	while ((temp /= base) > 0)
		len++;
	if (!(res = malloc(sizeof(char) * len)))
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		n *= -1;
	while (len--)
	{
		res[len] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	if (sign)
		res[0] = '-';
	return (res);
}
