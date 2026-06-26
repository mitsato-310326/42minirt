/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 21:32:04 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/27 02:00:51 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

void	*ft_lstsearch(t_list *lst, int index)
{
	int	i;

	if (index < 1)
		return (NULL);
	i = 1;
	while (i++ < index)
		lst = lst->next;
	return (lst->content);
}
