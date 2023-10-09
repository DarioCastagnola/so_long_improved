/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:43:42 by dcastagn          #+#    #+#             */
/*   Updated: 2023/03/10 10:06:24 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_game *game)
{
	locate_door(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
		game->imgx, game->imgy);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->door_open_img,
		(game->door_x) * 64, ((game->door_y) * 64));
	game->end = 1;
}

int	locate_door(t_game *game)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < get_y(game->map))
	{
		j = 0;
		while (j < ft_strlen(game->map[0]))
		{
			if (game->map[i][j] == 'E')
			{
				game->door_y = i;
				game->door_x = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	print_moves(t_game *game)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(game->player_moves);
	str = ft_strjoin("Mosse: ", temp);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, 64, 0);
	mlx_string_put(game->mlx, game->mlx_win, 20, 10, 0xFF0000, str);
	free(str);
	free(temp);
}

void	lose(char *message)
{
	ft_printf("\033[0;31m" "%s\n" "\033[0m", message);
	exit(1);
}
