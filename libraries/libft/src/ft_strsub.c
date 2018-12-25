/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 18:30:49 by skunz             #+#    #+#             */
/*   Updated: 2018/09/23 18:30:50 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!(sub = ft_strnew(len)) || !s)
		return (NULL);
	while (len--)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
