/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexbig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:31:51 by dcastagn          #+#    #+#             */
/*   Updated: 2023/10/09 16:07:25 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexbig(unsigned int n, int *count)
{
	if (n <= 9)
		ft_putchar(n + '0', count);
	if (n == 10)
		ft_putchar('A', count);
	if (n == 11)
		ft_putchar('B', count);
	if (n == 12)
		ft_putchar('C', count);
	if (n == 13)
		ft_putchar('D', count);
	if (n == 14)
		ft_putchar('E', count);
	if (n == 15)
		ft_putchar('F', count);
	if (n >= 16)
	{
		ft_hexbig(n / 16, count);
		ft_hexbig(n % 16, count);
	}
	return (*count);
}
