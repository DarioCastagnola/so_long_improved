/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:10:58 by dcastagn          #+#    #+#             */
/*   Updated: 2023/03/13 11:35:39 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Return how many '\n' are in <file> */
int	file_linecount(char *file)
{
	char	*l;
	int		fd;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(write(1, "Error\nMap not found\n", 20));
	j = 0;
	l = get_next_line(fd);
	if (!l)
		null_error("Mappa vuota");
	i = ft_strlen(l) - 1;
	while (l)
	{
		if (l[ft_strlen(l) - 1] == '\n')
			l[ft_strlen(l) - 1] = 0;
		free(l);
		l = get_next_line(fd);
		j++;
	}
	close(fd);
	return (j);
}

char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;
	int		line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		null_error("Errore nell'apertura del file");
	line = file_linecount(file);
	if (line == 0)
		return (0);
	map = (char **)malloc(sizeof(char *) * (line + 1));
	if (!map)
		null_error_freemap("Errore nell'allocazione di memoria", fd, map);
	i = -1;
	while (++i < line)
		map[i] = get_next_line(fd);
	map[line] = 0;
	i = -1;
	if (!is_valid_map(map))
		null_error_freemap("Mappa non valida", fd, map);
	close(fd);
	return (map);
}

int	ft_strlen_file(char *file)
{
	int		fd;
	char	c;
	int		readcount;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c != '\n')
			i++;
		if (c == '\n')
			break ;
	}
	close(fd);
	return (i);
}

void	baron_animation_file(t_game *game)
{
	game->baron1 = mlx_xpm_file_to_image(game->mlx, "xpm/baron1.xpm",
			&game->img_width, &game->img_height);
	game->baron2 = mlx_xpm_file_to_image(game->mlx, "xpm/baron2.xpm",
			&game->img_width, &game->img_height);
	game->baron3 = mlx_xpm_file_to_image(game->mlx, "xpm/baron3.xpm",
			&game->img_width, &game->img_height);
	game->baron4 = mlx_xpm_file_to_image(game->mlx, "xpm/baron4.xpm",
			&game->img_width, &game->img_height);
}
