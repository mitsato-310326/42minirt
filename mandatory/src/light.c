/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:55:50 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/27 16:01:47 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "minirt.h"

t_light_list	*ft_llstnew(void *content)
{
	return ((void *)ft_hlstnew(content));
}

void	ft_llstadd_front(t_light_list **lst, t_light_list *newl)
{
	ft_hlstadd_front((t_hittable_list **)lst, (t_hittable_list *)newl);
}

void	ft_llstclear(t_light_list **lst)
{
	ft_hlstclear((t_hittable_list **)lst);
}
