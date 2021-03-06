/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 00:07:14 by skunz             #+#    #+#             */
/*   Updated: 2018/12/27 11:00:42 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"
# include "eventhandler.h"
# include "draw.h"
# include "map.h"
# include "window.h"
# include "raycast.h"
# include "floorcast.h"

# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define TXT_COUNT 10
# define TXT_SIZE 64

typedef struct	s_game
{
	int			status;
	t_mlx		mlx;
	t_map		map;
	t_calc		calc;
	t_floor		floor;
	t_image		image;
	t_texture	*texture;
}				t_game;

enum	e_error
{
	e_none,
	e_map_invalid,
	e_malloc,
	e_open_file,
	e_usage,
	e_map_mult_start,
	e_map_no_start,
	e_map_start_oom,
	e_texture
};

/*
** main.c
*/

void			ft_error(int code);
void			ft_load_texture(t_game *game);
void			ft_set_sky(t_game *g);

/*
** draw.c
*/

void			ft_draw(t_game *game);

/*
** raycast_main.c
*/

void			ft_raycast(t_game *g);

/*
** raycast_wall.c
*/

void			ft_wall(t_game *g, int x);

/*
** floorcast.c
*/

void			ft_floor(t_game *g, int x);

/*
** movement.c
*/

void			ft_rotate(t_game *g, int dir);
void			ft_move(t_game *g, int dir);
void			ft_strafe(t_game *g, int dir);

int				ft_mouse_move(int x, int y, void *param);

#endif
