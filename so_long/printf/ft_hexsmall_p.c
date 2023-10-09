/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexsmall_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <dcastagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:31:55 by dcastagn          #+#    #+#             */
/*   Updated: 2023/10/09 16:07:13 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexsmall_p(unsigned long n, int *count)
{
	if (n <= 9)
		ft_putchar(n + '0', count);
	if (n == 10)
		ft_putchar('a', count);
	if (n == 11)
		ft_putchar('b', count);
	if (n == 12)
		ft_putchar('c', count);
	if (n == 13)
		ft_putchar('d', count);
	if (n == 14)
		ft_putchar('e', count);
	if (n == 15)
		ft_putchar('f', count);
	if (n >= 16)
	{
		ft_hexsmall_p(n / 16, count);
		ft_hexsmall_p(n % 16, count);
	}
	return (*count);
}
