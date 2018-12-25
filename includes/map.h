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

# include "struct.h"

int		get_width(char *column);
void	get_size(t_map *map, int fd);
void	get_map(t_map *map, const char *filename);

#endif
