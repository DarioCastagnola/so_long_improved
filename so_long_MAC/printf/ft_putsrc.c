/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsrc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:04:32 by dcastagn          #+#    #+#             */
/*   Updated: 2023/02/06 16:51:52 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsrc(char c, int *count, va_list ptr)
{
	int	i;

	i = 0;
	if (c == '%')
		ft_putchar('%', count);
	if (c == 'c')
		ft_putchar(va_arg(ptr, int), count);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ptr, int), count);
	if (c == 'u')
		ft_putbignbr(va_arg(ptr, unsigned int), count);
	if (c == 's')
		ft_putstr(va_arg(ptr, char *), count);
	if (c == 'x')
		ft_hexsmall(va_arg(ptr, unsigned int), count);
	if (c == 'X')
		ft_hexbig(va_arg(ptr, unsigned int), count);
	if (c == 'p')
		ft_putaddress(va_arg(ptr, unsigned long), count);
}	
