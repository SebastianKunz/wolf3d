/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 01:09:33 by skunz             #+#    #+#             */
/*   Updated: 2018/12/22 01:09:33 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_calc(t_calc *calc, t_map map)
{
	calc->pos_x = map.start_x;
	calc->pos_y = map.start_y;
	calc->dir_x = -1;
	calc->dir_y = 0;
	calc->plane_x = 0;
	calc->plane_y = 0.66;
	calc->time = 0;
	calc->oldtime = 0;
}

void	ft_get_frames(t_calc *calc)
{
	calc->oldtime = calc->time;
	calc->time = clock();
	// calc->frametime = (calc->time - calc->oldtime) / 1000;
	calc->frametime = 0.06;
	calc->move_speed = calc->frametime * 5;
	calc->rot_speed = calc->frametime * 3;
}

void	ft_step(t_calc *calc)
{
	if (calc->ray_dir_x < 0)
	{
		calc->step_x = -1;
		calc->side_dist_x = (calc->pos_x - calc->map_x)
			* calc->delta_dist_x;
	}
	else
	{
		calc->step_x = 1;
		calc->side_dist_x = (calc->map_x + 1.0 - calc->pos_x)
			* calc->delta_dist_x;
	}
	if (calc->ray_dir_y < 0)
	{
		calc->step_y = -1;
		calc->side_dist_y = (calc->pos_y - calc->map_y)
			* calc->delta_dist_y;
	}
	else
	{
		calc->step_y = 1;
		calc->side_dist_y = (calc->map_y + 1.0 - calc->pos_y)
			* calc->delta_dist_y;
	}
}

void	ft_dda(t_game *g)
{
	int hit;

	hit = 0;
	while (!hit)
	{
		if (g->calc.side_dist_x < g->calc.side_dist_y)
		{
			g->calc.side_dist_x += g->calc.delta_dist_x;
			g->calc.map_x += g->calc.step_x;
			g->calc.side = 0;
		}
		else
		{
			g->calc.side_dist_y += g->calc.delta_dist_y;
			g->calc.map_y += g->calc.step_y;
			g->calc.side = 1;
		}
		if (g->map.level[g->calc.map_x][g->calc.map_y] > 0)
			hit = 1;
	}
}

void	ft_calc_ray(t_calc *calc, int x)
{
	calc->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	calc->ray_dir_x = calc->dir_x + calc->plane_x * calc->camera_x;
	calc->ray_dir_y = calc->dir_y + calc->plane_y * calc->camera_x;
	calc->map_x = (int)calc->pos_x;
	calc->map_y = (int)calc->pos_y;
	calc->delta_dist_x = fabs(1 / calc->ray_dir_x);
	calc->delta_dist_y = fabs(1 / calc->ray_dir_y);
}

void	ft_wall(t_game *g, int x)
{
	int index;

	index = g->map.level[g->calc.map_x][g->calc.map_y] - 1;
	if (index < 0 || index > TXT_COUNT)
		index = 0;
	if (g->calc.side == 0)
		g->calc.wall_x = g->calc.pos_y + g->calc.prep_wall_dist * g->calc.ray_dir_y;
	else
		g->calc.wall_x = g->calc.pos_x + g->calc.prep_wall_dist * g->calc.ray_dir_x;
	g->calc.wall_x -= floor((g->calc.wall_x));
	g->calc.text_x = (int)(g->calc.wall_x * (double)TXT_SIZE);
	if (g->calc.side == 0 && g->calc.ray_dir_x > 0)
		g->calc.text_x = TXT_SIZE - g->calc.text_x - 1;
	if (g->calc.side == 1 && g->calc.ray_dir_y < 0)
		g->calc.text_x = TXT_SIZE - g->calc.text_x - 1;
	for (int y = g->calc.y_start; y < g->calc.y_end; y++)
	{
		g->calc.d = y * 256 - WIN_HEIGHT * 128 + g->calc.line_height * 128;
		g->calc.text_y = ((g->calc.d * TXT_SIZE) / g->calc.line_height) / 256;
		g->calc.color = *(int *)&g->texture[index].data[(g->calc.text_x * g->texture[index].bpp >> 3) + (g->calc.text_y * g->texture[index].sizeline)];
		if (g->calc.side == 1)
			g->calc.color = (g->calc.color >> 1) & 8355711;
		ft_put_pixel_in_image(&g->image, x, y, g->calc.color);
	}
}

void	ft_raycast(t_game *g)
{
	int x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		ft_calc_ray(&g->calc, x);
		ft_step(&g->calc);
		ft_dda(g);
		if (g->calc.side == 0)
			g->calc.prep_wall_dist = (g->calc.map_x - g->calc.pos_x + (1 - g->calc.step_x) / 2) / g->calc.ray_dir_x;
		else
			g->calc.prep_wall_dist = (g->calc.map_y - g->calc.pos_y + (1 - g->calc.step_y) / 2) / g->calc.ray_dir_y;
		g->calc.line_height = (int)(WIN_HEIGHT / g->calc.prep_wall_dist);
		g->calc.y_start = -g->calc.line_height / 2 + WIN_HEIGHT / 2;
		if (g->calc.y_start < 0)
			g->calc.y_start = 0;
		g->calc.y_end = g->calc.line_height / 2 + WIN_HEIGHT / 2;
		if (g->calc.y_end >= WIN_HEIGHT)
			g->calc.y_end = WIN_HEIGHT - 1;
		ft_wall(g, x);
		ft_get_frames(&g->calc);
	}

}
