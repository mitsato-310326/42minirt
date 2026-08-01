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

bool	within_radius(t_vec_three point, double radius)
{
	return (point.x * point.x + point.z * point.z < radius * radius);
}

bool	cyl_hit_controller(double best_t, t_hit_record *rec, void *cylinder,
		t_ray *r)
{
	rec->t = best_t;
	rec->color = ((t_hittable *)cylinder)->color;
	rec->p = ray_at(*r, best_t);
	return (true);
}

t_cyl_ret	cyl_wei(t_quaternion info, t_trange t_range,
			t_quaternion q_inv, t_ray sub)
{
	t_cyl_ret	ret;
	double		t;
	t_vec_three	local_p;
	int			i;

	ret.hit_anything = false;
	ret.best_t = t_range.t_max;
	i = -1;
	while (++i < 2)
	{
		if (i == 0)
			t = info.x;
		else
			t = info.y;
		if (t < t_range.t_min || t > ret.best_t)
			continue ;
		local_p = vec_three_add(sub.p_origin, vec_three_mult(sub.v_dir, t));
		if (local_p.y < 0 || local_p.y > info.z)
			continue ;
		ret.hit_anything = true;
		ret.best_t = t;
		ret.best_normal_local = rotate_vector(vec_three_mult(
					(t_vec_three){local_p.x, 0, local_p.z}, 1 / info.w), q_inv);
	}
	return (ret);
}

bool	hit_cylinder(t_trange t_range, void *cylinder, t_ray *r,
		t_hit_record *rec)
{
	t_cyl_locals	s;
	t_cylinder		*cy;
	t_cyl_ret		ret;
	t_quaternion	info;
	t_ray			sub;

	cy = (t_cylinder *)((t_hittable *)cylinder)->object_unique_info;
	init_cyl_locals(&s, cy, r);
	if (s.discriminant > 0)
	{
		info = (t_quaternion){(-s.half_b - sqrt(s.discriminant)) / s.a,
			(-s.half_b + sqrt(s.discriminant)) / s.a,
			s.height, s.radius};
		sub = (t_ray){s.sub_origin, s.sub_dir};
		ret = cyl_wei(info, t_range, s.q_inv, sub);
		s.hit_anything = ret.hit_anything;
		s.best_t = ret.best_t;
		s.best_normal_local = ret.best_normal_local;
	}
	cylinder_check_caps(&s, t_range);
	return (s.hit_anything
		&& cyl_hit_controller(s.best_t, rec, cylinder, r)
		&& set_face_normal(r, &s.best_normal_local, rec));
}
