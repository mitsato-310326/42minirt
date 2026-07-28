/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:37:15 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/28 22:20:00 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	cyl_hit_controller(double best_t, t_hit_record *rec, void *cylinder,
		t_ray *r)
{
	rec->t = best_t;
	rec->color = ((t_hittable *)cylinder)->color;
	rec->p = ray_at(*r, best_t);
	return (true);
}

/* forward: implemented in cylinder_utils.c */
extern t_cyl_ret	cyl_wei(t_quaternion info, t_trange t_range,
		t_quaternion q_inv, t_ray sub);

bool	hit_cylinder(t_trange t_range, void *cylinder, t_ray *r,
		t_hit_record *rec)
{
	t_cyl_locals	s;
	t_cylinder	*cy;
	t_cyl_ret	ret;

	cy = (t_cylinder *)((t_hittable *)cylinder)->object_unique_info;
	init_cyl_locals(&s, cy, r);
	if (s.discriminant > 0)
	{
		ret = cyl_wei(
			(t_quaternion){(-s.half_b - sqrt(s.discriminant)) / s.a,
				(-s.half_b + sqrt(s.discriminant)) / s.a,
				s.height, s.radius},
			t_range,
			(t_quaternion){-s.q.x, -s.q.y, -s.q.z, s.q.w},
			(t_ray){s.sub_origin, s.sub_dir});
		s.hit_anything = ret.hit_anything;
		s.best_t = ret.best_t;
		s.best_normal_local = ret.best_normal_local;
	}
	cylinder_check_caps(&s, t_range);
	return (s.hit_anything
		&& cyl_hit_controller(s.best_t, rec, cylinder, r)
		&& set_face_normal(r, &s.best_normal_local, rec));
}
