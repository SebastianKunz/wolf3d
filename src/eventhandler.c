/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:32:41 by skunz             #+#    #+#             */
/*   Updated: 2018/12/21 17:32:41 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move(t_game *g, int dir)
{
	if (dir == 1)
	{
		if (!g->map.level[(int)(g->calc.pos_x + g->calc.dir_x * g->calc.move_speed)][(int)g->calc.pos_y])
			g->calc.pos_x += g->calc.dir_x * g->calc.move_speed;
		if (!g->map.level[(int)g->calc.pos_x][(int)(g->calc.pos_y + g->calc.dir_y * g->calc.move_speed)])
			g->calc.pos_y += g->calc.dir_y * g->calc.move_speed;
	}
	else
	{
		if (!g->map.level[(int)(g->calc.pos_x - g->calc.dir_x * g->calc.move_speed)][(int)g->calc.pos_y])
			g->calc.pos_x -= g->calc.dir_x * g->calc.move_speed;
		if (!g->map.level[(int)g->calc.pos_x][(int)(g->calc.pos_y - g->calc.dir_y * g->calc.move_speed)])
			g->calc.pos_y -= g->calc.dir_y * g->calc.move_speed;
	}
}

void	ft_rotate(t_game *g, int dir)
{
	double	old_dir_x;
	double	old_plane_x;

	if (dir == 1)
	{
		old_dir_x = g->calc.dir_x;
		g->calc.dir_x = g->calc.dir_x * cos(-g->calc.rot_speed) - g->calc.dir_y * sin(-g->calc.rot_speed);
		g->calc.dir_y = old_dir_x * sin(-g->calc.rot_speed) + g->calc.dir_y * cos(-g->calc.rot_speed);
		old_plane_x = g->calc.plane_x;
		g->calc.plane_x = g->calc.plane_x * cos(-g->calc.rot_speed) - g->calc.plane_y * sin(-g->calc.rot_speed);
		g->calc.plane_y = old_plane_x * sin(-g->calc.rot_speed) + g->calc.plane_y * cos(-g->calc.rot_speed);
	}
	else
	{
		old_dir_x = g->calc.dir_x;
		g->calc.dir_x = g->calc.dir_x * cos(g->calc.rot_speed) - g->calc.dir_y * sin(g->calc.rot_speed);
		g->calc.dir_y = old_dir_x * sin(g->calc.rot_speed) + g->calc.dir_y * cos(g->calc.rot_speed);
		old_plane_x = g->calc.plane_x;
		g->calc.plane_x = g->calc.plane_x * cos(g->calc.rot_speed) - g->calc.plane_y * sin(g->calc.rot_speed);
		g->calc.plane_y = old_plane_x * sin(g->calc.rot_speed) + g->calc.plane_y * cos(g->calc.rot_speed);
	}
}

void	ft_set_black(t_game *g)
{
	int y;
	int x;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			ft_put_pixel_in_image(&g->image, x, y, 0);
	}
}

int		ft_keydown(int key, void *param)
{
	t_game *g;

	g = (t_game*)param;
	if (key == 53 || key == 12)
	{
		//free everything hehe
		exit(1);
	}
	else if (key == 126)
		ft_move(g, 1);
	else if (key == 125)
		ft_move(g, 0);
	else if (key == 124)
		ft_rotate(g, 1);
	else if (key == 123)
		ft_rotate(g, 0);
	if (key >= 123 && key <= 126)
	{
		ft_set_black(g);
		ft_raycast(g);
		ft_draw(g);
	}

	return (0);
}
