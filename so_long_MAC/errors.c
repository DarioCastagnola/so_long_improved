/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:40:53 by dcastagn          #+#    #+#             */
/*   Updated: 2023/03/10 10:50:29 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*null_error(char *message)
{
	ft_printf("\033[0;31m" " Error\n    %s\n" "\033[0m", message);
	exit(1);
}

void	*null_error_freemap(char *message, int fd, char	**map)
{
	ft_printf("\033[0;31m" " Error\n    %s\n" "\033[0m", message);
	close(fd);
	free(map);
	exit(1);
}

void	*null_error_wfile(char *message, int fd)
{
	ft_printf("\033[0;31m" " Error\n    %s\n" "\033[0m", message);
	close(fd);
	exit(1);
}

void	null_error_woexit(char *message)
{
	ft_printf("\033[0;31m" " Error\n    %s\n" "\033[0m", message);
	return ;
}

void	win(char *message)
{
	ft_printf("\033[0;32m" "%s\n" "\033[0m", message);
	exit(1);
}
