/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:09:39 by skunz             #+#    #+#             */
/*   Updated: 2018/09/19 18:09:41 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_badcode(int *i, int *count, int *k, int *plen)
{
	int len;

	*i = 0;
	*count = (*k)++;
	len = *plen - *k;
	return (len);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int count;
	int k;
	int plen;

	i = 0;
	plen = len;
	count = -1;
	k = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*(haystack + ++count) && len--)
	{
		if (*(haystack + count) == needle[i++])
		{
			if (!needle[i])
				return ((char*)haystack + count - i + 1);
		}
		else
			len = ft_badcode(&i, &count, &k, &plen);
	}
	return (NULL);
}
