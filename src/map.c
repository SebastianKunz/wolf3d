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

void	set_player(t_map *map, char *col, int x, int y)
{
	static int isonly = 0;

	if (ft_strcmp(col, "X") == 0 && !isonly)
	{
		if (x == 0 || x == map->width - 1)
			ft_error(e_map_start_oom);
		if (y == 0 || y == map->height - 1)
			ft_error(e_map_start_oom);
		map->start_x = y;
		map->start_y = x;
		isonly = 1;
	}
	else if (ft_strcmp(col, "X") == 0 && isonly)
		ft_error(e_map_mult_start);
	if (!isonly && y == map->height - 1)
		ft_error(e_map_no_start);
}

void	populate_level(t_map *map, char *line, int x, int y)
{
	char **col;

	col = ft_strsplit(line, ' ');
	while (col[++x])
	{
		set_player(map, col[x], x, y);
		map->level[y][x] = ft_atoi(col[x]);
		if (map->level[y][x] == 0 && (y == 0 || y == map->height - 1
			|| x == 0 || x == map->width - 1))
			map->level[y][x] = 1;
		if (map->level[y][x] < 0 || map->level[y][x] > TXT_COUNT)
			map->level[y][x] = 0;
		free(col[x]);
	}
	free(col);
}

int		get_width(char *column)
{
	int i;
	int count;

	i = -1;
	count = 1;
	while (column[++i])
	{
		if ((ft_isdigit(column[i]) || column[i] == 'X') &&
			(column[i + 1] == ' ' || column[i + 1] == '\n'))
			count++;
		else if (ft_isalpha(column[i]))
		{
			free(column);
			ft_error(e_map_invalid);
		}
	}
	return (count);
}

void	get_size(t_map *map, const char *filename)
{
	char	*line;
	int		i;
	int		fd;

	i = -1;
	if ((fd = open(filename, O_RDWR)) == -1)
		ft_error(e_open_file);
	if (!get_next_line(fd, &line))
		ft_error(e_open_file);
	map->width = get_width(line);
	map->height = 1;
	free(line);
	while (get_next_line(fd, &line))
	{
		if (map->width == get_width(line))
			map->height++;
		else
		{
			free(line);
			ft_error(e_map_invalid);
		}
		free(line);
	}
	close(fd);
}

void	get_map(t_map *map, const char *filename)
{
	char	*line;
	int		x;
	int		y;
	int		fd;

	y = -1;
	get_size(map, filename);
	if (!(map->level = malloc(sizeof(int*) * map->height)))
		ft_error(e_map_invalid);
	if ((fd = open(filename, O_RDWR)) == -1)
		ft_error(e_open_file);
	while (get_next_line(fd, &line) > 0)
	{
		x = -1;
		if (!(map->level[++y] = malloc(sizeof(int) * map->width)))
			ft_error(e_malloc);
		populate_level(map, line, x, y);
		free(line);
	}
}
