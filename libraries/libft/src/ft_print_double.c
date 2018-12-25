/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 11:48:35 by skunz             #+#    #+#             */
/*   Updated: 2018/12/09 11:48:38 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_double(long double n, int accuracy)
{
	int			ipart;
	long double	fpart;

	ipart = (int)n;
	fpart = n - (long double)ipart;
	ft_putnbr(ipart);
	if (accuracy > 0)
	{
		ft_putchar('.');
		fpart *= ft_pow(10, accuracy);
		if (fpart < 0)
			fpart *= -1;
		ft_putnbr((int)fpart);
	}
}
