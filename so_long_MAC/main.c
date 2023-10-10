/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:45:14 by dcastagn          #+#    #+#             */
/*   Updated: 2023/03/13 11:44:23 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		null_error("Wrong Input!!");
	game.end = 0;
	game.player_moves = 0;
	game.mlx = mlx_init();
	game.map = read_map(argv[1]);
	is_valid_map(game.map);
	ft_check_input(argv[1]);
	game.mlx_win = mlx_new_window(game.mlx,
			ft_strlen_file(argv[1]) * 64,
			file_linecount(argv[1]) * 64, "so_long");
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, ft_destroy_window, &game);
	img_init(&game);
	draw_map(&game);
	print_moves(&game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
}

int	ft_destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(ft_printf("You left the Summoner's Rift!\n"));
}

void	ft_check_input(char *s)
{
	int	l;

	l = ft_strlen(s);
	if (!(s[l - 1] == 'r' && s[l - 2] == 'e' && s[l - 3]
			== 'b' && s[l - 4] == '.'))
		null_error("Map isnt in .ber format");
}

void	frame_setter(t_game *game)
{
	static int	frame;

	if (frame == 60)
		frame = 0;
	frame++;
	game->frame = frame;
}

int	render(t_game *game)
{
	usleep(5000);
	frame_setter(game);
	if (locate_baron(game))
		animate_baron(game);
	return (0);
}
