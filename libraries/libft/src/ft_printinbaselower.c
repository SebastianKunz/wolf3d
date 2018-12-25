/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printinbaselower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 22:37:47 by skunz             #+#    #+#             */
/*   Updated: 2018/10/22 22:59:45 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printinbaselower(int base, long long nb)
{
	if (nb >= base)
	{
		ft_printinbaselower(base, nb / base);
		ft_printinbaselower(base, nb % base);
	}
	else
	{
		if (nb >= 10)
			ft_putchar(nb + 'a' - 10);
		else
			ft_putnbr(nb);
	}
}
