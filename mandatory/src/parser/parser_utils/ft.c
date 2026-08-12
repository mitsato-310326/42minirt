/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:01:19 by keitotak          #+#    #+#             */
/*   Updated: 2026/08/11 15:40:43 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}

void	*ft_realloc(void *p, size_t size)
{
	void	*mem;
	char	*str;

	if (p == NULL)
		return (malloc(size));
	str = (char *)p;
	if (ft_strlen(str) + 1 >= size)
		return (p);
	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_strlcpy((char *)mem, str, size);
	free(p);
	return (mem);
}

void	*ft_lstsearch(t_list *lst, int index)
{
	int	i;

	if (index < 0)
		return (NULL);
	i = 0;
	while (lst && i++ < index)
		lst = lst->next;
	if (lst == NULL)
		return (NULL);
	return (lst->content);
}
