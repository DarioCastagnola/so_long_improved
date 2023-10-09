/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:52:26 by dcastagn          #+#    #+#             */
/*   Updated: 2023/01/27 16:29:51 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	num;

	num = n;
	len = ft_len(n);
	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (0);
	ptr[len--] = '\0';
	if (num == 0)
		ptr[0] = '0';
	if (num < 0)
	{
		ptr[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		ptr[len--] = 48 + (num % 10);
		num = num / 10;
	}
	return (ptr);
}
