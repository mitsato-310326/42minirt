/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:37:15 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/26 14:47:13 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	within_radius(t_vec_three point, double radius)
{
	return (point.x * point.x + point.z * point.z < radius * radius);
}

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
	return (set_q((t_vec_three){from.y * to.z - from.z * to.y, from.z * to.x
			- from.x * to.z, from.x * to.y - from.y * to.x}, dot));
}

t_vec_three	rotate_vector(t_vec_three v, t_quaternion q)
{
	t_vec_three	q_vec;
	t_vec_three	t;
	t_vec_three	v_rotated;

	q_vec = (t_vec_three){q.x, q.y, q.z};
	t = (t_vec_three){2.0f * (q_vec.y * v.z - q_vec.z * v.y), 2.0f * (q_vec.z
			* v.x - q_vec.x * v.z), 2.0f * (q_vec.x * v.y - q_vec.y * v.x)};
	v_rotated = (t_vec_three){v.x + q.w * t.x + (q_vec.y * t.z - q_vec.z * t.y),
		v.y + q.w * t.y + (q_vec.z * t.x - q_vec.x * t.z), v.z + q.w * t.z
		+ (q_vec.x * t.y - q_vec.y * t.x)};
	return (v_rotated);
}

bool	cyl_hit_controller(double best_t, t_hit_record *rec, void *cylinder,
		t_ray *r)
{
	rec->t = best_t;
	rec->color = ((t_hittable *)cylinder)->color;
	rec->p = ray_at(*r, best_t);
	return (true);
}

typedef struct s_cyl_ret
{
	bool hit_anything;
	double best_t;
	t_vec_three best_normal_local;
	
}	t_cyl_ret;

t_cyl_ret cyl_wei(t_quaternion info, t_trange t_range, t_quaternion q_inv, t_ray sub)
{
	t_cyl_ret ret;
	double y_hit;
	t_vec_three local_p;

	ret.hit_anything = false;
    ret.best_t = INFINITY;

	y_hit = sub.p_origin.y + info.x * sub.v_dir.y;
	if ((y_hit >= 0 && y_hit <= info.z) && info.x < t_range.t_max
		&& info.x > t_range.t_min)
	{
		ret.best_t = info.x;
		local_p = ray_at(sub, ret.best_t);
		ret.best_normal_local = rotate_vector((t_vec_three){local_p.x / info.w, 0, local_p.z / info.w}, q_inv);
		ret.hit_anything = true;
	}
	y_hit = sub.p_origin.y + info.y * sub.v_dir.y;
	if ((y_hit >= 0 && y_hit <= info.z) && info.y < ret.best_t
		&& info.y < t_range.t_max && info.y > t_range.t_min)
	{
		ret.best_t = info.y;
		local_p = ray_at(sub, ret.best_t);
		ret.best_normal_local = rotate_vector((t_vec_three){local_p.x / info.w, 0, local_p.z / info.w}, q_inv);
		ret.hit_anything = true;
	}
	return(ret);
}

bool	hit_cylinder(t_trange t_range, void *cylinder, t_ray *r,
		t_hit_record *rec)
{
	double			radius;
	t_quaternion	q;
	t_vec_three		origin;
	double			height;
	t_vec_three		sub_dir;
	t_vec_three		sub_origin;
	t_vec_three		sub_dir_bottom;
	t_vec_three		sub_origin_bottom;
	double			half_b;
	double			a;
	double			discriminant;
	bool			hit_anything;
	double			best_t;
	t_vec_three		best_normal_local;
	t_quaternion	q_inv;
	// double			root;
	// double			temp;
	// double			y_hit;
	// t_vec_three		outward_normal_local;
	double			t_bottom;
	double			t_top;
	// t_vec_three		local_p;

	radius = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->radius;
	q = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->q;
	q_inv = (t_quaternion){-q.x, -q.y, -q.z, q.w};
	origin = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->origin;
	height = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->height;
	sub_dir = rotate_vector(r->v_dir, q);
	sub_origin = rotate_vector(vec_three_neg(r->p_origin, origin), q);
	sub_dir_bottom = (t_vec_three){sub_dir.x, 0, sub_dir.z};
	sub_origin_bottom = (t_vec_three){sub_origin.x, 0, sub_origin.z};
	half_b = dot(sub_origin_bottom, sub_dir_bottom);
	a = dot(sub_dir_bottom, sub_dir_bottom);
	discriminant = half_b * half_b - (dot(sub_origin_bottom, sub_origin_bottom)
			- radius * radius) * dot(sub_dir_bottom, sub_dir_bottom);
	hit_anything = false;
	best_t = INFINITY;
	if (discriminant > 0)
	{
		t_cyl_ret ret = cyl_wei((t_quaternion){(-half_b - sqrt(discriminant)) / a, (-half_b + sqrt(discriminant)) / a, height, radius}, t_range, (t_quaternion){-q.x, -q.y, -q.z, q.w}, (t_ray){sub_origin, sub_dir});
		hit_anything = ret.hit_anything;
		best_t = ret.best_t;
		best_normal_local = ret.best_normal_local;
	}
	if (sub_dir.y != 0)
	{
		t_bottom = -sub_origin.y / sub_dir.y;
		if ((t_range.t_min < t_bottom && t_bottom < best_t
				&& t_bottom < t_range.t_max)
			&& within_radius(vec_three_add(vec_three_mult(sub_dir_bottom,
						t_bottom), sub_origin_bottom), radius))
		{
			best_t = t_bottom;
			hit_anything = true;
			best_normal_local = rotate_vector((t_vec_three){0, -1, 0}, q_inv);
		}
		t_top = (height - sub_origin.y) / sub_dir.y;
		if ((t_range.t_min < t_top && t_top < best_t && t_top < t_range.t_max)
			&& within_radius(vec_three_add(vec_three_mult(sub_dir_bottom,
						t_top), sub_origin_bottom), radius))
		{
			best_t = t_top;
			hit_anything = true;
			best_normal_local = rotate_vector((t_vec_three){0, 1, 0}, q_inv);
		}
	}
	return (hit_anything && cyl_hit_controller(best_t, rec, cylinder, r)
		&& set_face_normal(r, &best_normal_local, rec));
}
