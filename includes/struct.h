/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:28:39 by skunz             #+#    #+#             */
/*   Updated: 2018/12/21 19:23:45 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_map
{
	int			start_x;
	int			start_y;
	int			**level;
	int			width;
	int			height;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef	struct	s_point
{
	int			start;
	int			end;
}				t_point;

typedef struct	s_calc
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		oldtime;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		prep_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	double		frametime;
	double		move_speed;
	double		rot_speed;
	double		wall_x;
	int			text_x;
	int			text_y;
	int			d;
	int			color;
	t_point		y;
}				t_calc;

typedef struct	s_image
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_image;

typedef	struct s_texture
{
	int			id;
	void		*img_ptr;
	char		*data;
	int			tex_width;
	int			tex_height;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_texture;

typedef struct  s_game
{
	t_mlx		mlx;
	t_map		map;
	t_calc		calc;
	t_image		image;
	t_texture	*texture;
}				t_game;

#endif
