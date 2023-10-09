/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:37:07 by dcastagn          #+#    #+#             */
/*   Updated: 2023/01/26 15:34:18 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	check_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
*/
char	*ft_strtrim(char const *s1, char const *set)
/*{
	size_t	end;
	char	*ptr;

	if (!s1 || !set)
		return (0);
	while (s1)
	{
		if (check_char((char)*s1, set))
			s1++;
		else
			break ;
	}
	end = ft_strlen(s1);
	while (end != 0)
	{
		if (check_char(s1[end - 1], set))
			end--;
		else
			break ;
	}
	ptr = (char *)malloc(end * sizeof(char) + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, (char *)s1, end + 1);
	return (ptr);
}
*/
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	while (s1[j] && ft_strchr(set, s1[j]))
		j++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, j, i - j + 1));
}
