/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 23:32:28 by skunz             #+#    #+#             */
/*   Updated: 2018/12/21 23:32:29 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
		"Wolfenstein 3D - skunz");
}

void	ft_init_image(t_image *image, t_mlx mlx)
{
	image->img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	image->data = mlx_get_data_addr(image->img_ptr, &image->bpp,
		&image->sizeline, &image->endian);
}

void	ft_put_pixel_in_image(t_image *image, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		*(int *)&image->data[(x * image->bpp >> 3) +
			(y * image->sizeline)] = color;
	}
}

void	ft_draw(t_game *game)
{
	char	*display;

	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->image.img_ptr, 0, 0);
	display = ft_itoa((int)(1.0 / game->calc.frametime));
	mlx_string_put(game->mlx.mlx_ptr, game->mlx.win_ptr, 0, 0,
		0x15b215, display);
	free(display);
}

void	ft_set_black(t_image *image)
{
	int y;
	int x;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			ft_put_pixel_in_image(image, x, y, 0);
	}
}
