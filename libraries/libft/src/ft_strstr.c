/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:09:46 by skunz             #+#    #+#             */
/*   Updated: 2018/09/19 18:09:48 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int count;
	int k;

	i = 0;
	count = -1;
	k = -1;
	if (!*needle)
		return ((char*)haystack);
	while (*(haystack + ++count))
	{
		if (*(haystack + count) == needle[i++])
		{
			if (!needle[i])
				return ((char*)haystack + count - i + 1);
		}
		else
		{
			i = 0;
			count = ++k;
		}
	}
	return (NULL);
}
