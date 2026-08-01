/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 22:23:25 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/30 00:00:00 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_quaternion	set_q(t_vec_three cross, double dot)
{
	t_quaternion	q;
	float			q_len;

	q.x = cross.x;
	q.y = cross.y;
	q.z = cross.z;
	q.w = 1.0f + dot;
	q_len = sqrtf(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
	q.x /= q_len;
	q.y /= q_len;
	q.z /= q_len;
	q.w /= q_len;
	return (q);
}

t_quaternion	set_quaternion(t_vec_three axis)
{
	t_vec_three	from;
	t_vec_three	to;
	float		dot;

	from = unit_vector(axis);
	to = unit_vector((struct s_vec_three){0, 1, 0});
	dot = from.x * to.x + from.y * to.y + from.z * to.z;
	if (dot < -0.999999f)
	{
		axis = (t_vec_three){0.0f, 0.0f, 1.0f};
		return ((t_quaternion){axis.x, axis.y, axis.z, 0.0f});
	}
	return (set_q((t_vec_three){from.y * to.z - from.z * to.y,
			from.z * to.x - from.x * to.z,
			from.x * to.y - from.y * to.x}, dot));
}

t_vec_three	rotate_vector(t_vec_three v, t_quaternion q)
{
	t_vec_three	q_vec;
	t_vec_three	t;
	t_vec_three	v_rotated;

	q_vec = (t_vec_three){q.x, q.y, q.z};
	t = (t_vec_three){2.0f * (q_vec.y * v.z - q_vec.z * v.y),
		2.0f * (q_vec.z * v.x - q_vec.x * v.z),
		2.0f * (q_vec.x * v.y - q_vec.y * v.x)};
	v_rotated = (t_vec_three){v.x + q.w * t.x + (q_vec.y * t.z - q_vec.z * t.y),
		v.y + q.w * t.y + (q_vec.z * t.x - q_vec.x * t.z),
		v.z + q.w * t.z + (q_vec.x * t.y - q_vec.y * t.x)};
	return (v_rotated);
}

void	cylinder_check_caps(t_cyl_locals *s, t_trange t_range)
{
	if (s->sub_dir.y == 0)
		return ;
	s->t_bottom = -s->sub_origin.y / s->sub_dir.y;
	if ((t_range.t_min < s->t_bottom && s->t_bottom < s->best_t
			&& s->t_bottom < t_range.t_max)
		&& within_radius(
			vec_three_add(vec_three_mult(s->sub_dir_bottom, s->t_bottom),
				s->sub_origin_bottom), s->radius))
	{
		s->best_t = s->t_bottom;
		s->hit_anything = true;
		s->best_normal_local = rotate_vector((t_vec_three){0, -1, 0}, s->q_inv);
	}
	s->t_top = (s->height - s->sub_origin.y) / s->sub_dir.y;
	if ((t_range.t_min < s->t_top && s->t_top < s->best_t
			&& s->t_top < t_range.t_max)
		&& within_radius(
			vec_three_add(vec_three_mult(s->sub_dir_bottom, s->t_top),
				s->sub_origin_bottom), s->radius))
	{
		s->best_t = s->t_top;
		s->hit_anything = true;
		s->best_normal_local = rotate_vector((t_vec_three){0, 1, 0}, s->q_inv);
	}
}

void	init_cyl_locals(t_cyl_locals *s, t_cylinder *cy, t_ray *r)
{
	s->radius = cy->radius;
	s->q = cy->q;
	s->q_inv = (t_quaternion){-s->q.x, -s->q.y, -s->q.z, s->q.w};
	s->origin = cy->origin;
	s->height = cy->height;
	s->sub_dir = rotate_vector(r->v_dir, s->q);
	s->sub_origin = rotate_vector(vec_three_neg(r->p_origin, s->origin),
			s->q);
	s->sub_dir_bottom = (t_vec_three){s->sub_dir.x, 0, s->sub_dir.z};
	s->sub_origin_bottom = (t_vec_three){s->sub_origin.x, 0,
		s->sub_origin.z};
	s->half_b = dot(s->sub_origin_bottom, s->sub_dir_bottom);
	s->a = dot(s->sub_dir_bottom, s->sub_dir_bottom);
	s->discriminant = s->half_b * s->half_b
		- (dot(s->sub_origin_bottom, s->sub_origin_bottom) - s->radius
			* s->radius) * dot(s->sub_dir_bottom, s->sub_dir_bottom);
	s->hit_anything = false;
	s->best_t = INFINITY;
}
