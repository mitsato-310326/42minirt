/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:18:37 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/27 15:04:50 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "lambertian.h"

// typedef

bool list_scatter(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, t_material *material)
{
	return material->scatter_fn(r_in, rec, attenuation, scattered, material);
	PERROR
	return false;
}

// bool scatter_metal(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, void *material)
// {
// 	t_vec_three tmp = unit_vector(r_in->v_dir);
// 	t_vec_three reflected = reflect(&tmp, &rec->normal);
// 	*scattered = (struct s_ray){rec->p, reflected};
// 	*attenuation = ((t_material *)material)->albedo;
// 	return (dot(scattered->v_dir, rec->normal) > 0);
// }

bool scatter(t_ray *r_in, t_hit_record *rec, t_vec_three *attenuation, t_ray *scattered, void *material)
{
	(void)r_in;

    // t_vec_three scatter_direction = vec_three_add(rec->normal, random_in_unit_sphere());
    t_vec_three scatter_direction = rec->normal;
    *scattered = (struct s_ray){rec->p, scatter_direction};
    *attenuation = ((t_material *)material)->albedo;
    return true;
}
