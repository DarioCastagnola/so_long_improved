/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:02:10 by dcastagn          #+#    #+#             */
/*   Updated: 2023/02/27 11:29:27 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *src, ...)
{
	int		i;
	int		count;
	va_list	ptr;

	va_start(ptr, src);
	i = 0;
	count = 0;
	while (src[i])
	{
		if (src[i] == '%')
		{
			i++;
			ft_putsrc(src[i], &count, ptr);
		}
		else
			ft_putchar(src[i], &count);
		i++;
	}
	return (count);
}
