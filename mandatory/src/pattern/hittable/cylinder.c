/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:37:15 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/21 18:55:52 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool within_radius(t_vec_three point, double radius)
{
    return(point.x * point.x + point.z * point.z < radius * radius);
}

t_quaternion set_quaternion(t_vec_three axis)
{
	t_vec_three from = unit_vector(axis);
	t_vec_three to = unit_vector((struct s_vec_three){0, 1, 0});
	float dot = from.x * to.x + from.y * to.y + from.z * to.z;

    if (dot < -0.999999f) {
        t_vec_three axis;
        axis = (t_vec_three){0.0f, 0.0f, 1.0f};
        return (t_quaternion){axis.x, axis.y, axis.z, 0.0f};
    }
    t_vec_three cross = {
        from.y * to.z - from.z * to.y,
        from.z * to.x - from.x * to.z,
        from.x * to.y - from.y * to.x
    };
    t_quaternion q;
    q.x = cross.x;
    q.y = cross.y;
    q.z = cross.z;
    q.w = 1.0f + dot;
    float q_len = sqrtf(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
    q.x /= q_len;
    q.y /= q_len;
    q.z /= q_len;
    q.w /= q_len;

    return q;
}

t_vec_three rotate_vector(t_vec_three v, t_quaternion q) {
    t_vec_three q_vec = {q.x, q.y, q.z};
    t_vec_three t = {
        2.0f * (q_vec.y * v.z - q_vec.z * v.y),
        2.0f * (q_vec.z * v.x - q_vec.x * v.z),
        2.0f * (q_vec.x * v.y - q_vec.y * v.x)
    };
    t_vec_three v_rotated = {
        v.x + q.w * t.x + (q_vec.y * t.z - q_vec.z * t.y),
        v.y + q.w * t.y + (q_vec.z * t.x - q_vec.x * t.z),
        v.z + q.w * t.z + (q_vec.x * t.y - q_vec.y * t.x)
    };

    return v_rotated;
}

bool hit_cylinder(double t_min, double t_max, void *cylinder, t_ray *r, t_hit_record *rec)
{
	double radius = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->radius;
	t_quaternion q = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->q;
	t_vec_three origin = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->origin;
	double height = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->height;

	t_vec_three sub_dir = rotate_vector(r->v_dir, q);
	t_vec_three sub_origin = rotate_vector(vec_three_neg(r->p_origin, origin), q);

	t_vec_three sub_dir_bottom = {sub_dir.x, 0, sub_dir.z};
	t_vec_three sub_origin_bottom = {sub_origin.x, 0, sub_origin.z};

	double half_b = dot(sub_origin_bottom, sub_dir_bottom);
	double a = dot(sub_dir_bottom, sub_dir_bottom);
	double discriminant = half_b*half_b - (dot(sub_origin_bottom, sub_origin_bottom) - radius * radius)*dot(sub_dir_bottom, sub_dir_bottom);

    bool hit_anything = false;
    double best_t = INFINITY;
    t_vec_three best_normal_local;
    t_quaternion q_inv = {-q.x, -q.y, -q.z, q.w};
	if (discriminant > 0)
	{
		double root = sqrt(discriminant);
		double temp = (-half_b - root) / a;
        double y_hit = sub_origin.y + temp * sub_dir.y;
		if ((y_hit >= 0 && y_hit <= height) && temp < t_max && temp > t_min) {
            best_t = temp;
            t_vec_three local_p = ray_at((t_ray){sub_origin, sub_dir}, best_t); // origin + t*dir
            t_vec_three outward_normal_local = {local_p.x / radius, 0, local_p.z / radius};
            best_normal_local = rotate_vector(outward_normal_local, q_inv);
            hit_anything = true;
		}
		temp = (-half_b + root) / a;
        y_hit = sub_origin.y + temp * sub_dir.y;
		if ((y_hit >= 0 && y_hit <= height) && temp < best_t && temp < t_max && temp > t_min){
            best_t = temp;
            t_vec_three local_p = ray_at((t_ray){sub_origin, sub_dir}, best_t); // origin + t*dir
            t_vec_three outward_normal_local = {local_p.x / radius, 0, local_p.z / radius};
            best_normal_local = rotate_vector(outward_normal_local, q_inv);
            hit_anything = true;
		}
    }
    if (sub_dir.y != 0)
    {
        double t_bottom = -sub_origin.y / sub_dir.y;
        if ((t_min < t_bottom && t_bottom < best_t && t_bottom < t_max) && within_radius(vec_three_add(vec_three_mult(sub_dir_bottom, t_bottom), sub_origin_bottom), radius))
        {
            best_t = t_bottom;
            hit_anything = true;
            best_normal_local = rotate_vector((t_vec_three){0, -1, 0}, q_inv);
        }
        double t_top = (height - sub_origin.y) / sub_dir.y;
        if ((t_min < t_top && t_top < best_t && t_top < t_max) && within_radius(vec_three_add(vec_three_mult(sub_dir_bottom, t_top), sub_origin_bottom), radius))
        {
            best_t = t_top;
            hit_anything = true;
            best_normal_local = rotate_vector((t_vec_three){0, 1, 0}, q_inv);
        }
    }
    if (hit_anything)
    {
        rec->t = best_t;
        rec->material = ((t_hittable *)cylinder)->material;
        rec->p = ray_at(*r, best_t);
        set_face_normal(r, &best_normal_local, rec);
        return true;
    }
    return false;
}
