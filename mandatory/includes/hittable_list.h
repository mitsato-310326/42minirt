/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/24 16:43:41 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

typedef struct s_hit_record t_hit_record;

typedef struct s_hittable_list
{
	struct s_hittable_list *next;
	void	          *content;
}			t_hittable_list;

bool list_hit(t_ray* r, double t_min, double t_max, t_hit_record* rec, t_hittable_list* top);
t_hittable_list	*ft_hlstnew(void *content);
void ft_hlstadd_front(t_hittable_list **lst, t_hittable_list *new);
void ft_hlstclear(t_hittable_list **lst);


#endif
