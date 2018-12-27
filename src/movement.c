/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:11:38 by skunz             #+#    #+#             */
/*   Updated: 2018/12/26 18:13:04 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_rotate(t_game *g, int dir)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->calc.dir_x;
	g->calc.dir_x = g->calc.dir_x * cos(g->calc.rot_speed * dir)
		- g->calc.dir_y * sin(g->calc.rot_speed * dir);
	g->calc.dir_y = old_dir_x * sin(g->calc.rot_speed * dir)
		+ g->calc.dir_y * cos(g->calc.rot_speed * dir);
	old_plane_x = g->calc.plane_x;
	g->calc.plane_x = g->calc.plane_x * cos(g->calc.rot_speed * dir)
		- g->calc.plane_y * sin(g->calc.rot_speed * dir);
	g->calc.plane_y = old_plane_x * sin(g->calc.rot_speed * dir)
		+ g->calc.plane_y * cos(g->calc.rot_speed * dir);
}

void	ft_move(t_game *g, int dir)
{
	if (dir == 1)
	{
		if (!g->map.level[(int)(g->calc.pos_x
			+ g->calc.dir_x * g->calc.move_speed)][(int)g->calc.pos_y])
			g->calc.pos_x += g->calc.dir_x * g->calc.move_speed;
		if (!g->map.level[(int)g->calc.pos_x][(int)(g->calc.pos_y
			+ g->calc.dir_y * g->calc.move_speed)])
			g->calc.pos_y += g->calc.dir_y * g->calc.move_speed;
	}
	else
	{
		if (!g->map.level[(int)(g->calc.pos_x
			- g->calc.dir_x * g->calc.move_speed)][(int)g->calc.pos_y])
			g->calc.pos_x -= g->calc.dir_x * g->calc.move_speed;
		if (!g->map.level[(int)g->calc.pos_x][(int)(g->calc.pos_y
			- g->calc.dir_y * g->calc.move_speed)])
			g->calc.pos_y -= g->calc.dir_y * g->calc.move_speed;
	}
}

void	ft_strafe(t_game *g, int dir)
{
	if (dir == -1)
	{
		if (!g->map.level[(int)(g->calc.pos_x
			+ g->calc.plane_x * g->calc.move_speed)][(int)g->calc.pos_y])
			g->calc.pos_x += g->calc.plane_x * g->calc.move_speed;
		if (!g->map.level[(int)g->calc.pos_x][(int)(g->calc.pos_y
			+ g->calc.plane_y * g->calc.move_speed)])
			g->calc.pos_y += g->calc.plane_y * g->calc.move_speed;
	}
	else
	{
		if (!g->map.level[(int)(g->calc.pos_x
			- g->calc.plane_x * g->calc.move_speed)][(int)g->calc.pos_y])
			g->calc.pos_x -= g->calc.plane_x * g->calc.move_speed;
		if (!g->map.level[(int)g->calc.pos_x][(int)(g->calc.pos_y
			- g->calc.plane_y * g->calc.move_speed)])
			g->calc.pos_y -= g->calc.plane_y * g->calc.move_speed;
	}
}
