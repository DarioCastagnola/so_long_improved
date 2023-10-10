/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:13:52 by dcastagn          #+#    #+#             */
/*   Updated: 2023/01/27 12:32:30 by dcastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*currentelement;

	currentelement = lst;
	if (currentelement == NULL)
		return (NULL);
	while (currentelement->next != NULL)
		currentelement = currentelement->next;
	return (currentelement);
}
