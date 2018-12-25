/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:38:00 by skunz             #+#    #+#             */
/*   Updated: 2018/12/21 17:27:32 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_width(char *column)
{
	int i;
	int count;

	i = -1;
	count = 1;
	while (column[++i])
		if (ft_isdigit(column[i]) && (column[i + 1] == ' ' ||
			column[i + 1] == '\n'))
			count++;
		else if (column[i] == 'X')
			count++;
	return (count);
}

void	get_size(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = -1;
	if (!get_next_line(fd, &line))
		ft_error(1);
	map->width = get_width(line);
	map->height = 1;
	free(line);
	while (get_next_line(fd, &line))
	{
		if (map->width == get_width(line))
			map->height++;
		else
			ft_error(1);
		free(line);
	}
	close(fd);
}

void	get_map(t_map *map, const char *filename)
{
	char	*line;
	char	**col;
	int		x;
	int 	y;
	int		fd;
	int		isonly;

	y = -1;
	isonly = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error(3);
	get_size(map, fd);
	if (!(map->level = malloc(sizeof(int*) * map->height)))
		ft_error(1);
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error(3);
	while (get_next_line(fd, &line) > 0)
	{
		x = -1;
		if (!(map->level[++y] = malloc(sizeof(int) * map->width)))
		{
			//ft_free2d(game->map.level, y + 1);
			ft_error(2);
		}
		col = ft_strsplit(line, ' ');
		while (col[++x])
		{
			if (ft_strcmp(col[x], "X") == 0 && !isonly)
			{
				if (x == 0 || x == map->width - 1)
					ft_error(7);
				if (y == 0 || y == map->height - 1)
					ft_error(7);
				map->start_x = y;
				map->start_y = x;
				isonly = 1;
			}
			else if (ft_strcmp(col[x], "X") == 0 && isonly)
			{
				//free all
				ft_error(5);
			}
			map->level[y][x] = ft_atoi(col[x]);
			free(col[x]);
		}
		free(col);
		free(line);
	}
	if (!isonly)
		ft_error(6);
}
