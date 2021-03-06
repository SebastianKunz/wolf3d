/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:56:57 by skunz             #+#    #+#             */
/*   Updated: 2018/12/06 17:56:59 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_uintlen(unsigned int u)
{
	size_t len;

	len = 1;
	while ((u = (u / 10)) > 0)
		len++;
	return (len);
}
