/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:29:52 by dcastagn          #+#    #+#             */
/*   Updated: 2023/03/13 11:44:48 by dcastagn         ###   ########.fr       */
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
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->floor, (game->baronx) * 64,
		((game->barony) * 64));
	if (game->frame >= 0 && game->frame < 12)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->baron1, (game->baronx) * 64,
			((game->barony) * 64));
	else if (game->frame >= 12 && game->frame < 24)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->baron2, (game->baronx) * 64,
			((game->barony) * 64));
	else if (game->frame >= 24 && game->frame < 36)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->baron3, (game->baronx) * 64,
			((game->barony) * 64));
	else if (game->frame >= 36 && game->frame < 48)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->baron4, (game->baronx) * 64,
			((game->barony) * 64));
	else if (game->frame >= 48 && game->frame < 64)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->baron1, (game->baronx) * 64,
			((game->barony) * 64));
}

int	locate_baron(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != 0)
		{
			if (game->map[i][j] == 'G')
			{
				game->barony = i;
				game->baronx = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
