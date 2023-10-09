/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:09:18 by dcastagn          #+#    #+#             */
/*   Updated: 2023/03/06 16:57:18 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	is_rect(char **map)
{
	size_t	i;
	size_t	x;
	size_t	y;

	y = get_y(map);
	x = ft_strlen(map[0]);
	i = 0;
	if (x - 1 == y)
	{
		null_error_woexit("Mappa quadrata !!!");
		return (0);
	}
	while (i < y)
	{
		if (!(ft_strlen(map[i]) == x))
			break ;
		i++;
	}
	if (i == y)
		return (1);
	null_error_woexit("Mappa quadrata o non rettangolare !!!");
	return (0);
}

int	border_wall(char **map)
{
	int	i;
	int	k;

	i = -1;
	k = ft_strlen(map[0]);
	while (map[0][++i] != 0)
	{
		if (map[0][i] != '1')
			return (0);
	}
	i = -1;
	while ((map[get_y(map) - 1][++i] != 0))
	{
		if (map[get_y(map) - 1][i] != '1')
			return (0);
	}
	i = -1;
	while (map[++i])
	{
		if ((map[i][0] != '1') || (map[i][k - 1] != '1'))
			return (0);
	}
	return (1);
}

int	check_entities(char **map)
{
	int	i;
	int	j;
	int	counter[3];

	i = -1;
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != 0)
		{
			if (map[i][j] == 'E')
				counter[0] = 1;
			if (map[i][j] == 'C')
				counter[1] = 1;
			if (map[i][j] == 'P')
				counter[2] = 1;
		}
	}
	if (counter[0] && counter[1] && counter[2])
		return (1);
	null_error_woexit("inserisci almeno 1 player/uscita/collezionabile !!!");
	return (0);
}

int	is_valid_map(char **map)
{
	int	j;
	int	i;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != 0)
		{
			if (!is_in_set(map[i][j]))
			{
				null_error_woexit("Invalid char in map!!!");
				return (0);
			}
		}
	}
	if (!is_rect(map) || !check_entities(map))
		return (0);
	if (!border_wall(map))
	{
		null_error_woexit("Il muro è aperto !!!");
		return (0);
	}
	else
		return (1);
}
