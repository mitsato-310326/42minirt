/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:37:15 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/09 20:44:09 by mitsato          ###   ########.fr       */
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

bool hit_cylinder(double t_min, double t_max, void *cylinder, t_ray *r, t_hit_record *rec)
{
	/*
		radius

		center <- (A, B, C)
		centerは計算上 (0, 0, 0) として扱いたいため
		world 全体 -(A, B, C) した上で計算していく。

		axis <- (P, Y, R)
		axisは計算上 (0, 1, 0) として扱いたいため
		world 全体 -(P, Y, R) した上で計算していく。

		r->v_dir <- (x1, y1, z1)
		world の回転に合わせ -(P, Y, R) した上で計算していく。

		r->p_origin <- (x2, y2, z2)
		world の座標に合わせ -(P, 0, R) した上で計算していく。
	*/

	// double radius = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->radius;
	// t_vec_three *center = &((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->origin;
	// // double height = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->height;
	// t_vec_three *axis = &((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->axis; // S
	// t_vec_three oc = vec_three_neg(r->p_origin, *center); //P1

	// double a = dot(r->v_dir, r->v_dir) - dot(*axis, r->v_dir) * dot(*axis, r->v_dir) / dot(*axis, *axis);
	// double half_b = dot(oc, r->v_dir) - dot(*axis, r->v_dir) * dot(oc, *axis) / dot(*axis, *axis);
	// double c = dot(oc, oc) - dot(oc, *axis) * dot(oc, *axis) / dot(*axis, *axis)  - radius * radius; //
	// double discriminant = half_b*half_b - a*c;
	// // printf("%f\n", discriminant);

	// if (discriminant > 0)
	// {
	// 	double root = sqrt(discriminant);
	// 	double temp = (-half_b - root) / a;
	// 	if (temp < t_max && temp > t_min) {
	// 		rec->t = temp;
	// 		rec->p = ray_at(*r, rec->t);
	// 		// t_vec_three outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1 / radius);
	// 		// set_face_normal(r, &outward_normal, rec);
	// 		rec->material = ((t_hittable *)cylinder)->material;
	// 		return true;
	// 	}
	// 	temp = (-half_b + root) / a;
	// 	if (temp < t_max && temp > t_min) {
	// 		rec->t = temp;
	// 		rec->p = ray_at(*r, rec->t);
	// 		// t_vec_three outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1 / radius);
	// 		// set_face_normal(r, &outward_normal, rec);
	// 		rec->material = ((t_hittable *)cylinder)->material;
	// 		return true;
	// 	}
	}
	return false;
}
