/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:29:52 by dcastagn          #+#    #+#             */
/*   Updated: 2023/10/13 15:59:23 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_set(char c)
{
	char	*set;
	int		i;

	set = "01CPEFG";
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	animate_baron(t_game *game)
{
	if (!locate_baron(game))
		return ;
	for (int i = 0; i < game->nenemies; i++)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, (game->baron[i].x) * 64,
			((game->baron[i].y) * 64));
		if (game->temperedfate == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->baron[i].gbaron, (game->baron[i].x) * 64,
				((game->baron[i].y) * 64));
		else if (game->frame >= 0 && game->frame < 12)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->baron[i].baron1, (game->baron[i].x) * 64,
				((game->baron[i].y) * 64));
		else if (game->frame >= 12 && game->frame < 24)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->baron[i].baron2, (game->baron[i].x) * 64,
				((game->baron[i].y) * 64));
		else if (game->frame >= 24 && game->frame < 36)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->baron[i].baron3, (game->baron[i].x) * 64,
				((game->baron[i].y) * 64));
		else if (game->frame >= 36 && game->frame < 48)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->baron[i].baron4, (game->baron[i].x) * 64,
				((game->baron[i].y) * 64));
		else if (game->frame >= 48 && game->frame < 64)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->baron[i].baron1, (game->baron[i].x) * 64,
				((game->baron[i].y) * 64));
	}
}

int	locate_baron(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	for (int idx = 0; idx < game->nenemies; idx++)
	{
		while (game->map[i])
		{
			j = 0;
			while (game->map[i][j] != 0)
			{
				if (game->map[i][j] == 'G')
				{
					game->baron[idx].y = i;
					game->baron[idx].x = j;
					idx++;
				}
				j++;
			}
			i++;
		}
	}
	return (1); //return 1 if u want the baron to stay visible after walked through(may cause confusion tho :P)
}

int locate_nenemies(t_game *game)
{
	int	i;
	int	j;

	game->nenemies = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != 0)
		{
			if (game->map[i][j] == 'G')
			{
				game->nenemies += 1;
			}
			j++;
		}
		i++;
	}
	return (1);
}
