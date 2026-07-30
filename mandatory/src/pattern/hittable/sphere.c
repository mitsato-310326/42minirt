/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:05:31 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/26 15:13:10 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	set_face_normal(t_ray *r, t_vec_three *outward_normal,
		t_hit_record *rec)
{
	rec->front_face = dot(r->v_dir, *outward_normal) < 0;
	if (rec->front_face)
		rec->normal = *outward_normal;
	else
		rec->normal = vec_three_mult(*outward_normal, -1.0);
	return (true);
}

bool	checkcolor(double temp, t_ray *r, t_hit_record *rec, void *sphere)
{
	t_vec_three	outward_normal;
	double		radius;
	t_vec_three	*center;

	radius = ((t_sphere *)((t_hittable *)sphere)->object_unique_info)->radius;
	center = &((t_sphere *)((t_hittable *)sphere)->object_unique_info)->origin;
	rec->t = temp;
	rec->p = ray_at(*r, rec->t);
	outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1
			/ radius);
	set_face_normal(r, &outward_normal, rec);
	rec->color = ((t_hittable *)sphere)->color;
	return (true);
}

static double	sphere_discriminant(t_ray *r, void *sphere, double *a,
					double *half_b)
{
	double		radius;
	t_vec_three	*center;
	t_vec_three	oc;

	radius = ((t_sphere *)((t_hittable *)sphere)->object_unique_info)->radius;
	center = &((t_sphere *)((t_hittable *)sphere)->object_unique_info)->origin;
	oc = vec_three_neg(r->p_origin, *center);
	*a = dot(r->v_dir, r->v_dir);
	*half_b = dot(oc, r->v_dir);
	return (*half_b * *half_b - *a * (dot(oc, oc) - radius * radius));
}

bool	hit_sphere(t_trange t_range, void *sphere, t_ray *r,
		t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	discriminant;
	double	root;

	discriminant = sphere_discriminant(r, sphere, &a, &half_b);
	if (discriminant <= 0)
		return (false);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root < t_range.t_max && root > t_range.t_min)
		return (checkcolor(root, r, rec, sphere));
	root = (-half_b + sqrt(discriminant)) / a;
	if (root < t_range.t_max && root > t_range.t_min)
		return (checkcolor(root, r, rec, sphere));
	return (false);
}
