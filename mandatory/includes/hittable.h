/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:58:40 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/26 14:49:44 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "ray_util.h"

typedef struct s_trange	t_trange;
typedef struct s_quaternion	t_quaternion;
typedef struct s_cylinder	t_cylinder;

typedef struct s_hit_record
{
	t_vec_three			p;
	t_vec_three			normal;
	t_vec_three			color;
	double				t;
	bool				front_face;
}						t_hit_record;

typedef struct s_hittable
{
	t_vec_three			color;
	bool			(*hit_fn)(t_trange t_range, void *hittable,
						t_ray *r, t_hit_record *rec);
	void			*object_unique_info;
}							t_hittable;

typedef struct s_cyl_ret
{
	bool				hit_anything;
	double				best_t;
	t_vec_three			best_normal_local;
}						t_cyl_ret;

typedef struct s_cyl_locals
{
	double				radius;
	t_quaternion		q;
	t_vec_three			origin;
	double				height;
	t_vec_three			sub_dir;
	t_vec_three			sub_origin;
	t_vec_three			sub_dir_bottom;
	t_vec_three			sub_origin_bottom;
	double				half_b;
	double				a;
	double				discriminant;
	bool				hit_anything;
	double				best_t;
	t_vec_three			best_normal_local;
	t_quaternion		q_inv;
	double				t_bottom;
	double				t_top;
}						t_cyl_locals;

bool					within_radius(t_vec_three point, double radius);
t_quaternion			set_q(t_vec_three cross, double dot);
t_quaternion			set_quaternion(t_vec_three axis);
t_vec_three				rotate_vector(t_vec_three v, t_quaternion q);
void					cylinder_check_caps(t_cyl_locals *s, t_trange t_range);
void					init_cyl_locals(t_cyl_locals *s, t_cylinder *cy,
							t_ray *r);
t_cyl_ret				cyl_wei(t_quaternion info, t_trange t_range,
							t_quaternion q_inv, t_ray sub);

#endif
