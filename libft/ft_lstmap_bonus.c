/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 23:29:55 by mitsato           #+#    #+#             */
/*   Updated: 2025/10/20 21:25:48 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstcpy(t_list *dst, t_list *src, void *(*f)(void *),
		void (*del)(void *))
{
	if (src->next == NULL)
	{
		(dst) = ft_lstnew(f(src->content));
		if (!dst)
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		return (dst);
	}
	else
	{
		(dst) = ft_lstnew(f(src->content));
		if (!dst)
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		(dst)->next = ft_lstcpy((dst)->next, src->next, f, del);
		return (dst);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;

	if (!lst || !lst->next)
	{
		dst = NULL;
		return (dst);
	}
	dst = ft_lstnew(f(lst->content));
	if (!dst)
	{
		ft_lstclear(&dst, del);
		return (NULL);
	}
	dst->next = ft_lstcpy(dst, lst->next, f, del);
	if (ft_lstsize(dst) != ft_lstsize(lst))
		return (NULL);
	return (dst);
}
