/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kusocode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:08:41 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/27 16:15:19 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light_list *create_lights()
{
	t_light_list *light = NULL;
	t_light *a_l = malloc(sizeof(t_light));
	t_vec_three point3a = (struct s_vec_three){5, 50, 5};
	a_l->pos = point3a;
	t_vec_three color3a = (struct s_vec_three){0.5, 1, 1};
	a_l->color = color3a;
	a_l->power = 0.7;

	return light;
}
