/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 21:32:04 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 00:52:23 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_lstsearch(t_list *lst, int index)
{
	int	i;

	if (index < 0)
		return (NULL);
	i = 0;
	while (i++ < index)
		lst = lst->next;
	return (lst->content);
}
