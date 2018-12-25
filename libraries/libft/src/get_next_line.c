/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:20:08 by skunz             #+#    #+#             */
/*   Updated: 2018/12/12 18:05:15 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_normi(int ret, char **keeper, int fd)
{
	if (ret == -1)
		return (-1);
	else if (ret == 0 && !keeper[fd])
		return (0);
	else
		return (1);
}

int		ft_attach(char **line, char **keeper)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*keeper)[i] && (*keeper)[i] != '\n')
		i++;
	if ((*keeper)[i] == '\n')
	{
		*line = ft_strsub(*keeper, 0, i);
		temp = ft_strdup(&((*keeper)[i + 1]));
		free(*keeper);
		*keeper = temp;
		if (!(*keeper)[0])
			ft_strdel(keeper);
	}
	else
	{
		*line = ft_strdup(*keeper);
		ft_strdel(keeper);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*keeper[MAX_FD];
	char			buff[BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	if (!line || fd < 0 || fd > MAX_FD)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!keeper[fd])
			keeper[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(keeper[fd], buff);
			free(keeper[fd]);
			keeper[fd] = temp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ft_normi(ret, keeper, fd) != 1)
		return (ft_normi(ret, keeper, fd));
	return (ft_attach(line, &keeper[fd]));
}
