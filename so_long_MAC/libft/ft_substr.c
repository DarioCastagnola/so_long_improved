/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:45:22 by dcastagn          #+#    #+#             */
/*   Updated: 2023/01/26 10:34:04 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	size_t	arr_size;
	char	*ptr;

	i = 0;
	if (!s)
		return (0);
	arr_size = 0;
	slen = ft_strlen(s);
	if (start < slen)
		arr_size = slen - start;
	if (arr_size > len)
		arr_size = len;
	ptr = (char *)malloc((arr_size + 1) * (sizeof(char)));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, (char *)s + start, arr_size + 1);
	return (ptr);
}
