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
	exit(code);
}

void	ft_printmap(t_game game)
{
	printf("Map width: %d\n", game.map.width);
	printf("Map height: %d\n", game.map.height);
	for (int y = 0; y < game.map.height; y++)
	{
		for (int x = 0; x < game.map.width; x++)
			printf("%d ", game.map.level[y][x]);
		printf("\n");
	}
}

void ft_init_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Wolf3d - Skunz");
}



int ft_close(void *param)
{
	t_game *game;

	game = (t_game*)param;
	// free all
	exit(0);
}

void	ft_load_image(t_game *game)
{
	int i;
	char *paths[TXT_COUNT + 1] = {
		"textures/redbrick.xpm",
		"textures/wood.xpm",
		"textures/greystone.xpm",
		"textures/bluestone.xpm",
		"textures/colorstone.xpm",
		"textures/eagle.xpm",
		"textures/greenlight.xpm",
		"textures/mossy.xpm",
		"textures/pillar.xpm",
		"textures/purplestone.xpm",
		"textures/barrel.xpm",
		"textures/intra.xpm",
		NULL
	};
	i = -1;
	game->texture = malloc(sizeof(t_texture) * TXT_COUNT);
	//check if files exists -> pointer == null
	while (++i < TXT_COUNT)
	{
		game->texture[i].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr, paths[i], &game->texture[i].tex_width, &game->texture[i].tex_height);
		game->texture[i].data = mlx_get_data_addr(game->texture[i].img_ptr, &game->texture[i].bpp, &game->texture[i].sizeline, &game->texture[i].endian);
	}
}

int main(int argc, char **argv)
{
	t_game game;
	if (argc == 2)
	{
		get_map(&game.map, argv[1]);
		ft_init_window(&game.mlx);
		ft_init_image(&game.image, game.mlx);
		//ft_printmap(game);
		ft_init_calc(&game.calc, game.map);
		ft_load_image(&game);
		ft_raycast(&game);

		mlx_put_image_to_window(game.mlx.mlx_ptr, game.mlx.win_ptr, game.image.img_ptr, 20, 20);
		ft_draw(&game);
		mlx_hook(game.mlx.win_ptr, 3, 0, ft_keydown, (void*)&game);
		mlx_hook(game.mlx.win_ptr, 17, 0, ft_close, (void*)&game);
		mlx_loop(game.mlx.mlx_ptr);
	}
	else
		ft_error(4);
	return (0);
}
