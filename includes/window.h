/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 21:29:22 by skunz             #+#    #+#             */
/*   Updated: 2018/12/24 21:29:24 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

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

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

#endif
