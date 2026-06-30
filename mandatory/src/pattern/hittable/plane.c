/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:37:15 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/21 16:56:50 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_plane(double t_min, double t_max, void *cylinder, t_ray *r,
		t_hit_record *rec)
{
	t_vec_three	*origin;
	t_vec_three	*normal;
	double		discriminant;
	double		temp;

	origin = &((t_plane *)((t_hittable *)cylinder)->object_unique_info)->origin;
	normal = &((t_plane *)((t_hittable *)cylinder)->object_unique_info)->normal;
	discriminant = (dot(*origin, *normal) - dot(r->p_origin, *normal)) / dot(r->v_dir, *normal);
	// printf("%f\n", r->p_origin.x);
	// printf("%f\n", r->p_origin.y);
	// printf("%f\n", r->p_origin.z);
	// printf("%f\n", normal->x);
	// printf("%f\n", normal->y);
	// printf("%f\n", normal->z);
	if (discriminant > 0)
	{
		temp = discriminant;
		if (temp < t_max && temp > t_min)
		{
			rec->t = temp;
			rec->p = ray_at(*r, rec->t);
			rec->front_face = true;
			rec->normal = *normal;
			rec->color = ((t_hittable *)cylinder)->color;
			return (true);
		}
	}
	return (false);
}
