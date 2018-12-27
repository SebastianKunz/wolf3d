/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 12:21:49 by skunz             #+#    #+#             */
/*   Updated: 2018/12/27 11:18:21 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_wall(t_game *g, int x, int index)
{
	int y;

	y = g->calc.y_start;
	while (y < g->calc.y_end)
	{
		g->calc.d = y * 256 - WIN_HEIGHT * 128 + g->calc.line_height * 128;
		g->calc.text_y = ((g->calc.d * TXT_SIZE) / g->calc.line_height) / 256;
		g->calc.color = *(int *)&g->texture[index].data[(g->calc.text_x
			* g->texture[index].bpp >> 3)
				+ (g->calc.text_y * g->texture[index].sizeline)];
		if (g->calc.side == 1)
			g->calc.color = (g->calc.color >> 1) & 8355711;
		ft_put_pixel_in_image(&g->image, x, y, g->calc.color);
		y++;
	}
}

void	ft_wall(t_game *g, int x)
{
	int index;

	index = g->map.level[g->calc.map_x][g->calc.map_y] - 1;
	if (g->calc.side == 0)
		g->calc.wall_x = g->calc.pos_y + g->calc.perp_wall_dist
			* g->calc.ray_dir_y;
	else
		g->calc.wall_x = g->calc.pos_x + g->calc.perp_wall_dist
			* g->calc.ray_dir_x;
	g->calc.wall_x -= floor((g->calc.wall_x));
	g->calc.text_x = (int)(g->calc.wall_x * (double)TXT_SIZE);
	if (g->calc.side == 0 && g->calc.ray_dir_x > 0)
		g->calc.text_x = TXT_SIZE - g->calc.text_x - 1;
	if (g->calc.side == 1 && g->calc.ray_dir_y < 0)
		g->calc.text_x = TXT_SIZE - g->calc.text_x - 1;
	ft_put_wall(g, x, index);
}

void	ft_get_frames(t_calc *calc)
{
	calc->oldtime = calc->time;
	calc->time = clock();
	calc->frametime = (calc->time - calc->oldtime) / 1000;
	calc->move_speed = calc->frametime * 15;
	calc->rot_speed = calc->frametime * 5;
}
