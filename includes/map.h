/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:38:52 by skunz             #+#    #+#             */
/*   Updated: 2018/12/21 17:27:44 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	int			start_x;
	int			start_y;
	int			**level;
	int			width;
	int			height;
}				t_map;

void			get_map(t_map *map, const char *filename);

#endif
