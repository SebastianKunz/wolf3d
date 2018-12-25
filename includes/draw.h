/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 00:05:23 by skunz             #+#    #+#             */
/*   Updated: 2018/12/22 00:05:24 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

int		ft_color(int r, int g, int b);
void	ft_init_image(t_image *image, t_mlx mlx);
void	ft_put_pixel_in_image(t_image *image, int x, int y, int color);
void	ft_draw(t_game *game);
void	ft_put_vline(t_image image, int x, t_point y, int color);

#endif
