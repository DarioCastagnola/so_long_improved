/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:07 by dcastagn          #+#    #+#             */
/*   Updated: 2023/01/24 10:32:40 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (*(char *)(s + i) == (char)c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (0);
}
