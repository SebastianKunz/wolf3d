/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 18:30:04 by skunz             #+#    #+#             */
/*   Updated: 2018/09/23 18:30:07 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*map;

	index = -1;
	if (!s)
		return (NULL);
	if (!(map = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[++index])
		map[index] = f(index, s[index]);
	map[index] = '\0';
	return (map);
}
