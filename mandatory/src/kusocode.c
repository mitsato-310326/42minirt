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

#include "minirt.h"
#include "light.h"

t_light_list *create_lights()
{
	t_light_list *light = NULL;
	t_light *a_l = malloc(sizeof(t_light));
	t_vec_three point3a = (struct s_vec_three){50, 5, -50};
	a_l->pos = point3a;
	t_vec_three color3a = (struct s_vec_three){1, 0, 1};
	a_l->color = color3a;
	a_l->power = 0.2;

	t_light *b_l = malloc(sizeof(t_light));
	t_vec_three point3b = (struct s_vec_three){-50, 5, -50};
	b_l->pos = point3b;
	t_vec_three color3b = (struct s_vec_three){1, 1, 1};
	b_l->color = color3b;
	b_l->power = 0.2;
	ft_llstadd_front(&light, ft_llstnew(a_l));
	ft_llstadd_front(&light, ft_llstnew(b_l));

	return light;
}
