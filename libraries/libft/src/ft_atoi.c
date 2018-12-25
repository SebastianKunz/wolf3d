/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:23:03 by skunz             #+#    #+#             */
/*   Updated: 2018/11/23 21:23:10 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		conv_str;
	short	sign;

	conv_str = 0;
	sign = 1;
	while (ft_iswhitespace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
		{
			conv_str *= -1;
			sign = -1;
		}
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		conv_str = conv_str * 10 + *nptr - '0';
		nptr++;
	}
	return (conv_str * sign);
}
