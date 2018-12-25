/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 11:59:45 by skunz             #+#    #+#             */
/*   Updated: 2018/12/09 11:59:46 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_pow(int base, int power)
{
	long long nb;

	nb = 1;
	if (power == 0)
		return (1);
	else if (base == 0)
		return (0);
	while (power--)
		nb *= base;
	return (nb);
}
