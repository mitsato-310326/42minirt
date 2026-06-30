/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kusocode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:08:41 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/28 15:20:35 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "minirt.h"

t_light_scene	*create_lights(void)
{
	t_light_scene			*a_l;
	t_vec_three		point3a;
	t_vec_three		color3a;

	a_l = malloc(sizeof(t_light_scene));
	point3a = (struct s_vec_three){50, 5, 50};
	a_l->crd = point3a;
	color3a = (struct s_vec_three){1, 0, 1};
	a_l->color = color3a;
	a_l->ratio = 0.2;
	return (a_l);
}
