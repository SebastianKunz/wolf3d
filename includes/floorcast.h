/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcast.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 23:56:28 by skunz             #+#    #+#             */
/*   Updated: 2018/12/24 23:56:29 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOORCAST_H
# define FLOORCAST_H

typedef struct	s_floor
{
	double		x_wall;
	double		y_wall;
	double		dist_wall;
	double		dist_player;
	double		current_dist;
	double		weight;
	double		current_x;
	double		current_y;
	int			text_x;
	int			text_y;
}				t_floor;

#endif
