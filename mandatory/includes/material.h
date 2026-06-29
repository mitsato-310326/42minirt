/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:06:13 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/24 16:43:19 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

#include "hittable_list.h"
#include "minirt.h"

typedef struct s_material
{
	t_ray *r_in;
	t_ray *scattered;
	t_vec_three attenuation;
	t_vec_three albedo;
	bool (* scatter_fn)(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, void *material);
}			t_material;

void reflect(t_hit_record *rec, t_vec_three *attenuation, t_ray *reflected, void *material);

#endif
