/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 23:54:52 by skunz             #+#    #+#             */
/*   Updated: 2018/12/24 23:54:53 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_set_direction(t_game *g)
{
	if (g->calc.side == 0 && g->calc.ray_dir_x > 0)
	{
		g->floor.x_wall = g->calc.map_x;
		g->floor.y_wall = g->calc.map_y + g->calc.wall_x;
	}
	else if (g->calc.side == 0 && g->calc.ray_dir_x < 0)
	{
		g->floor.x_wall = g->calc.map_x + 1.0;
		g->floor.y_wall = g->calc.map_y + g->calc.wall_x;
	}
	else if (g->calc.side == 1 && g->calc.ray_dir_y > 0)
	{
		g->floor.x_wall = g->calc.map_x + g->calc.wall_x;
		g->floor.y_wall = g->calc.map_y;
	}
	else
	{
		g->floor.x_wall = g->calc.map_x + g->calc.wall_x;
		g->floor.y_wall = g->calc.map_y + 1.0;
	}
}

/*
** for ceiling
**
** g->calc.color = *(int *)&g->texture[1].data[(g->floor.text_x
** * (g->texture[1].bpp >> 3)) + (g->floor.text_y * g->texture[1].sizeline)];
** ft_put_pixel_in_image(&g->image, x, WIN_HEIGHT - y, g->calc.color);
*/

void	ft_floor(t_game *g, int x)
{
	int y;

	ft_set_direction(g);
	g->floor.dist_wall = g->calc.perp_wall_dist;
	g->floor.dist_player = 0.0;
	if (g->calc.y_end < 0)
		g->calc.y_end = WIN_HEIGHT;
	y = g->calc.y_end;
	while (++y < WIN_HEIGHT)
	{
		g->floor.current_dist = WIN_HEIGHT / (2.0 * y - WIN_HEIGHT);
		g->floor.weight = (g->floor.current_dist - g->floor.dist_player)
			/ (g->floor.dist_wall - g->floor.dist_player);
		g->floor.current_x = g->floor.weight * g->floor.x_wall
			+ (1.0 - g->floor.weight) * g->calc.pos_x;
		g->floor.current_y = g->floor.weight * g->floor.y_wall
			+ (1.0 - g->floor.weight) * g->calc.pos_y;
		g->floor.text_x = (int)(g->floor.current_x * TXT_SIZE) % TXT_SIZE;
		g->floor.text_y = (int)(g->floor.current_y * TXT_SIZE) % TXT_SIZE;
		g->calc.color = *(int *)&g->texture[2].data[(g->floor.text_x *
			(g->texture[2].bpp >> 3)) + (g->floor.text_y *
			g->texture[2].sizeline)];
		ft_put_pixel_in_image(&g->image, x, y, g->calc.color);
	}
}
