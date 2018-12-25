/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 00:07:14 by skunz             #+#    #+#             */
/*   Updated: 2018/12/21 17:34:03 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h> // delete

# include "mlx.h"
# include "libft.h"

# include "eventhandler.h"
# include "draw.h"
# include "map.h"
# include "window.h"
# include "raycast.h"

# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define TXT_COUNT 12
# define TXT_SIZE 64

typedef struct	s_game
{
	t_mlx		mlx;
	t_map		map;
	t_calc		calc;
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

void	ft_error(int code);

// draw.c
void	ft_draw(t_game *game);

void	ft_init_image(t_image *image, t_mlx mlx);

void	ft_raycast(t_game *g);
void	ft_load_image(t_game *game);

#endif
