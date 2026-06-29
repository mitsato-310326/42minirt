/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:05:31 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/21 16:18:57 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_face_normal(t_ray *r, t_vec_three *outward_normal,
		t_hit_record *rec)
{
	rec->front_face = dot(r->v_dir, *outward_normal) < 0;
	if (rec->front_face)
		rec->normal = *outward_normal;
	else
		rec->normal = vec_three_mult(*outward_normal, -1.0);
}

bool	hit_sphere(double t_min, double t_max, void *sphere, t_ray *r,
		t_hit_record *rec)
{
	double		radius;
	t_vec_three	*center;
	t_vec_three	oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		root;
	double		temp;
	t_vec_three	outward_normal;

	radius = ((t_sphere *)((t_hittable *)sphere)->object_unique_info)->radius;
	center = &((t_sphere *)((t_hittable *)sphere)->object_unique_info)->origin;
	oc = vec_three_neg(r->p_origin, *center);
	a = dot(r->v_dir, r->v_dir);
	half_b = dot(oc, r->v_dir);
	c = dot(oc, oc) - radius * radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant > 0)
	{
		root = sqrt(discriminant);
		temp = (-half_b - root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec->t = temp;
			rec->p = ray_at(*r, rec->t);
			outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1
					/ radius);
			set_face_normal(r, &outward_normal, rec);
			rec->material = ((t_hittable *)sphere)->material;
			return (true);
		}
		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec->t = temp;
			rec->p = ray_at(*r, rec->t);
			outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1
					/ radius);
			set_face_normal(r, &outward_normal, rec);
			rec->material = ((t_hittable *)sphere)->material;
			return (true);
		}
	}
	return (false);
}
