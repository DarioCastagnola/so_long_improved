/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:53:01 by dcastagn          #+#    #+#             */
/*   Updated: 2023/03/13 11:33:46 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bard_img_init(t_game *game)
{
	game->bard = mlx_xpm_file_to_image(game->mlx,
			"xpm/bardD.xpm", &game->img_width, &game->img_height);
	game->bard_d = mlx_xpm_file_to_image(game->mlx,
			"xpm/bardD.xpm", &game->img_width, &game->img_height);
	game->bard_l = mlx_xpm_file_to_image(game->mlx,
			"xpm/bardL.xpm", &game->img_width, &game->img_height);
	game->bard_r = mlx_xpm_file_to_image(game->mlx,
			"xpm/bardR.xpm", &game->img_width, &game->img_height);
	game->bard_u = mlx_xpm_file_to_image(game->mlx,
			"xpm/bardU.xpm", &game->img_width, &game->img_height);
}

void	img_init(t_game *game)
{
	bard_img_init(game);
	baron_animation_file(game);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"xpm/river.xpm", &game->img_width, &game->img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"xpm/borders.xpm", &game->img_width, &game->img_height);
	game->pickups = mlx_xpm_file_to_image(game->mlx,
			"xpm/chime.xpm", &game->img_width, &game->img_height);
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"xpm/doorO.xpm", &game->img_width, &game->img_height);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"xpm/doorC.xpm", &game->img_width, &game->img_height);
	game->obstacle = mlx_xpm_file_to_image(game->mlx,
			"xpm/bush.xpm", &game->img_width, &game->img_height);
}

void	selector_2(t_game *game, char c)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
			game->imgx, game->imgy);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bard,
			game->imgx, game->imgy);
	}
	if (c == 'F')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
			game->imgx, game->imgy);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->obstacle,
			game->imgx, game->imgy);
	}
	if (c == 'G')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
			game->imgx, game->imgy);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->baron1,
			game->imgx, game->imgy);
	}
}

void	selector(t_game *game, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall,
			game->imgx, game->imgy);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
			game->imgx, game->imgy);
	if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
			game->imgx, game->imgy);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->door_close_img,
			game->imgx, game->imgy);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
			game->imgx, game->imgy);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->pickups,
			game->imgx, game->imgy + 10);
	}
	else
		selector_2(game, c);
}

void	draw_map(t_game *game)
{
	int		i;
	size_t	j;

	i = -1;
	game->imgx = 0;
	game->imgy = 0;
	while (++i < get_y(game->map))
	{
		j = -1;
		while (++j < ft_strlen(game->map[0]))
		{
			selector(game, game->map[i][j]);
			game->imgx += 64;
		}
		game->imgx = 0;
		game->imgy += 64;
	}
}
