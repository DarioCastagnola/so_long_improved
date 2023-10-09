/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:42 by dcastagn          #+#    #+#             */
/*   Updated: 2023/01/23 16:27:10 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	while (size >= 0)
	{
		if (s[size] == (unsigned char)c)
			return ((char *)(s + size));
		size--;
	}
	return (0);
}
