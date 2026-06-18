/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:37:15 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/15 20:40:14 by mitsato          ###   ########.fr       */
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

t_quaternion set_quaternion(t_vec_three axis)
{
	t_vec_three from = unit_vector(axis);
	t_vec_three to = unit_vector((struct s_vec_three){0, 1, 0});
	float dot = from.x * to.x + from.y * to.y + from.z * to.z;

    // 3. 例外処理：2つのベクトルが完全に真逆（180度）を向いている場合
    if (dot < -0.999999f) {
        // 真逆の場合、外積が0になって軸が決まらないので、
        // to（今回は真上）と直交する適当な軸（例：X軸）を中心に180度回転させる
        t_vec_three axis;
        // if (fabsf(to.y) > 0.9f) { // もしtoが真上なら、Z軸を回転軸にする
            axis = (t_vec_three){0.0f, 0.0f, 1.0f};
        // }
        return (t_quaternion){axis.x, axis.y, axis.z, 0.0f};
    }

    // 4. 外積（Cross Product）を計算。これがクォータニオンの「軸」のベースになる
    t_vec_three cross = {
        from.y * to.z - from.z * to.y,
        from.z * to.x - from.x * to.z,
        from.x * to.y - from.y * to.x
    };

    // 5. クォータニオンの各成分を計算（半角の公式の変形）
    t_quaternion q;
    q.x = cross.x;
    q.y = cross.y;
    q.z = cross.z;
    q.w = 1.0f + dot; // 数学的なトリックにより、ここを「1 + 内積」にする

    // 6. 最後にクォータニオンを正規化して完成
    float q_len = sqrtf(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
    q.x /= q_len;
    q.y /= q_len;
    q.z /= q_len;
    q.w /= q_len;

    return q;
}

t_vec_three rotate_vector(t_vec_three v, t_quaternion q) {
    // クォータニオンの積 (q * v * q^-1) をベクトル用に最適化した計算式
    // 内部的には3次元の行列掛け算や、外積の組み合わせと同じ意味
    t_vec_three q_vec = {q.x, q.y, q.z};

    // t = 2 * cross(q_vec, v)
    t_vec_three t = {
        2.0f * (q_vec.y * v.z - q_vec.z * v.y),
        2.0f * (q_vec.z * v.x - q_vec.x * v.z),
        2.0f * (q_vec.x * v.y - q_vec.y * v.x)
    };

    // v_rotated = v + q.w * t + cross(q_vec, t)
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
	t_quaternion q = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->q; // S
	t_vec_three origin = ((t_cylinder *)((t_hittable *)cylinder)->object_unique_info)->origin; // S

	t_vec_three sub_dir = rotate_vector(r->v_dir, q);
	t_vec_three sub_origin = rotate_vector(r->p_origin, q);

	t_vec_three sub_dir_bottom = {sub_dir.x, 0, sub_dir.z};
	t_vec_three sub_origin_bottom = {sub_origin.x - origin.x, 0, sub_origin.z - origin.z};

	double half_b = dot(sub_origin_bottom, sub_dir_bottom);
	double a = dot(sub_dir_bottom, sub_dir_bottom);
	double discriminant = half_b*half_b - (dot(sub_origin_bottom, sub_origin_bottom) - radius * radius)*dot(sub_dir_bottom, sub_dir_bottom);

	if (discriminant > 0)
	{
		double root = sqrt(discriminant);
		double temp = (-half_b - root) / a;
		if (temp < t_max && temp > t_min) {
			rec->t = temp;
			rec->p = ray_at(*r, rec->t);
			// t_vec_three outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1 / radius);
			// set_face_normal(r, &outward_normal, rec);
			rec->material = ((t_hittable *)cylinder)->material;
			return true;
		}
		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min) {
			rec->t = temp;
			rec->p = ray_at(*r, rec->t);
			// t_vec_three outward_normal = vec_three_mult(vec_three_neg(rec->p, *center), 1 / radius);
			// set_face_normal(r, &outward_normal, rec);
			rec->material = ((t_hittable *)cylinder)->material;
			return true;
		}
	}
	return false;
}
