/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:37:15 by mitsato           #+#    #+#             */
/*   Updated: 2026/09/03 20:12:42 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_plane(t_trange t_range, void *cylinder, t_ray *r, t_hit_record *rec)
{
	t_vec_three	*origin;
	t_vec_three	*normal;
	double		discriminant;
	double		temp;

	origin = &((t_plane *)((t_hittable *)cylinder)->object_unique_info)->origin;
	normal = &((t_plane *)((t_hittable *)cylinder)->object_unique_info)->normal;
	discriminant = (dot(*origin, *normal) - dot(r->p_origin, *normal))
		/ dot(r->v_dir, *normal);
	if (discriminant > 0)
	{
		temp = discriminant;
		if (temp < t_range.t_max && temp > t_range.t_min)
		{
			rec->t = temp;
			rec->p = ray_at(*r, rec->t);
			rec->color = ((t_hittable *)cylinder)->color;
			rec->front_face = dot(r->v_dir, *normal) <= 0;
			rec->normal = *normal;
			if (!rec->front_face)
				rec->normal = vec_three_neg((t_vec_three){0, 0, 0}, *normal);
			return (true);
		}
	}
	return (false);
}
