/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:37:15 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/09 19:32:45 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void set_face_normal(t_ray *r, t_vec_three *outward_normal, t_hit_record *rec)
// {
// 	rec->front_face = dot(r->v_dir, *outward_normal) < 0;
// 	if (rec->front_face)
// 		rec->normal = *outward_normal;
// 	else
// 		rec->normal = vec_three_mult(*outward_normal, -1.0);
// }

bool hit_plane(double t_min, double t_max, void *cylinder, t_ray *r, t_hit_record *rec)
{
	t_vec_three *origin = &((t_plane *)((t_hittable *)cylinder)->object_unique_info)->origin;
	t_vec_three *normal = &((t_plane *)((t_hittable *)cylinder)->object_unique_info)->normal;

	double discriminant = (dot(*origin, *normal) - dot(r->p_origin, *normal)) / dot(r->v_dir, *normal);
	// printf("%f\n", discriminant);

	// double a = dot(r->v_dir, r->v_dir) - dot(*axis, r->v_dir) * dot(*axis, r->v_dir) / dot(*axis, *axis);
	// double half_b = dot(oc, r->v_dir) - dot(*axis, r->v_dir) * dot(oc, *axis) / dot(*axis, *axis);
	// double c = dot(oc, oc) - dot(oc, *axis) * dot(oc, *axis) / dot(*axis, *axis)  - radius * radius; //
	// double discriminant = half_b*half_b - a*c;
	// printf("%f\n", discriminant);

	if (discriminant > 0)
	{
		// double root = sqrt(discriminant);
		double temp = discriminant;
		if (temp < t_max && temp > t_min)
		{
			rec->t = temp;
			rec->p = ray_at(*r, rec->t);
			// t_vec_three outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1 / radius);
			// set_face_normal(r, &outward_normal, rec);
			rec->front_face = true;
			rec->normal = *normal;
			rec->material = ((t_hittable *)cylinder)->material;
			return true;
		}
	}
	return false;
}
