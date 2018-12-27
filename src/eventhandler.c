/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventhandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:32:41 by skunz             #+#    #+#             */
/*   Updated: 2018/12/26 18:56:17 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(void *param)
{
	t_game *game;

	game = (t_game*)param;
	exit(0);
}

int		ft_mouse_move(int x, int y, void *param)
{
	static int	prev_x = WIN_WIDTH / 2;
	t_game		*game;

	game = (t_game*)param;
	if (prev_x > x)
		ft_rotate(game, 1);
	else if (prev_x < x)
		ft_rotate(game, -1);
	(void)y;
	prev_x = x;
	game->status = 1;
	return (0);
}

int		ft_keydown(int key, void *param)
{
	t_game *g;

	g = (t_game*)param;
	if (key == 53 || key == 12)
		exit(1);
	else if (key == 126 || key == 13)
		ft_move(g, 1);
	else if (key == 125 || key == 1)
		ft_move(g, 0);
	else if (key == 124)
		ft_rotate(g, -1);
	else if (key == 123)
		ft_rotate(g, 1);
	else if (key == 0)
		ft_strafe(g, 1);
	else if (key == 2)
		ft_strafe(g, -1);
	if ((key >= 123 && key <= 126) || (key >= 0 && key <= 2) || key == 13)
		g->status = 1;
	return (0);
}
