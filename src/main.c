/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunz <skunz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:04:28 by skunz             #+#    #+#             */
/*   Updated: 2018/12/21 19:43:45 by skunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_error(int code)
{
	if (code == 1)
		ft_putstr("Map invalid!\n");
	else if (code == 2)
		ft_putstr("Malloc failed\n");
	else if (code == 3)
		ft_putstr("Failed to open file\n");
	else if (code == 4)
		ft_putstr("usage: ./wolf3d [mapname]\n");
	else if (code == 5)
		ft_putstr("Map invalid: More than one startpoint!\n");
	else if (code == 6)
		ft_putstr("Map invalid: No starting point!\n");
	else if (code == 7)
		ft_putstr("Map invalid: starting point is out of map!\n");
	else if (code == 8)
		ft_putstr("Failed to load texture!\n");
	exit(code);
}

void	ft_load_texture(t_game *game)
{
	int			i;
	static char	*paths[TXT_COUNT + 1] = {
		"textures/redbrick.xpm", "textures/wood.xpm",
		"textures/greystone.xpm", "textures/bluestone.xpm",
		"textures/colorstone.xpm", "textures/eagle.xpm",
		"textures/mossy.xpm", "textures/purplestone.xpm",
		"textures/intra.xpm", "textures/hitler.xpm",
		"textures/intra_hitler.xpm", "textures/skybox.xpm",
		NULL
	};

	i = -1;
	if (!(game->texture = malloc(sizeof(t_texture) * TXT_COUNT)))
		ft_error(e_malloc);
	while (++i < TXT_COUNT)
	{
		if (!(game->texture[i].img_ptr = mlx_xpm_file_to_image(
			game->mlx.mlx_ptr, paths[i], &game->texture[i].tex_width,
				&game->texture[i].tex_height)))
			ft_error(e_texture);
		game->texture[i].data = mlx_get_data_addr(
			game->texture[i].img_ptr, &game->texture[i].bpp,
			&game->texture[i].sizeline, &game->texture[i].endian);
	}
}

int		ft_refresh(t_game *game)
{
	if (game->status)
	{
		ft_set_sky(game);
		ft_raycast(game);
		ft_draw(game);
	}
	game->status = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		get_map(&game.map, argv[1]);
		ft_init_window(&game.mlx);
		ft_init_image(&game.image, game.mlx);
		ft_load_texture(&game);
		ft_init_calc(&game.calc, game.map);
		game.status = 1;
		mlx_hook(game.mlx.win_ptr, 6, 0, ft_mouse_move, (void*)&game);
		mlx_hook(game.mlx.win_ptr, 3, 0, ft_keydown, (void*)&game);
		mlx_hook(game.mlx.win_ptr, 17, 0, ft_close, (void*)&game);
		mlx_loop_hook(game.mlx.mlx_ptr, ft_refresh, (void*)&game);
		mlx_loop(game.mlx.mlx_ptr);
	}
	else
		ft_error(e_usage);
	return (0);
}
