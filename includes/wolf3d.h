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

#ifndef WOLFD3D_H
# define WOLFD3D_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h> // delete

# include "mlx.h"
# include "libft.h"
# include "map.h"
# include "eventhandler.h"
# include "draw.h"
# include "raycast.h"

# define WIN_WIDTH 1080
# define WIN_HEIGHT 720

# define TXT_COUNT 12

# define TXT_SIZE 64

void	ft_error(int code);
void texture_test(t_game game, void *xpm_text);

#endif
