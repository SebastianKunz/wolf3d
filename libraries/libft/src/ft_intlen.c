/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:43:50 by skunz             #+#    #+#             */
/*   Updated: 2018/10/05 19:43:52 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function returns the amount of digits (including the sign) in an int.
**
**	Examples:
**
**		ft_intlen(42) = 2
**		ft_intlen(-42) = 3
*/

#include "libft.h"

size_t	ft_intlen(int n)
{
	size_t len;

	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while ((n = (n / 10)) > 0)
		len++;
	return (len);
}
