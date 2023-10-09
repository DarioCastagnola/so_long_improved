/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:50:33 by dcastagn          #+#    #+#             */
/*   Updated: 2023/03/09 12:02:50 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != 0)
		{
			if (game->map[i][j] == 'P')
			{
				game->bardy = i;
				game->bardx = j;
			}
			j++;
		}
		i++;
	}
}

void	set_chimes(t_game *game)
{
	int		i;
	size_t	j;
	int		counter;

	counter = 0;
	i = 0;
	while (i < get_y(game->map))
	{
		j = 0;
		while (j < ft_strlen(game->map[0]))
		{
			if (game->map[i][j] == 'C')
			{
				counter++;
			}
			j++;
		}
		i++;
	}
	game->numchimes = counter;
}
