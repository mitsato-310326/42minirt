/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/26 14:55:50 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYSICS_H
# define PHYSICS_H

# include "ray_util.h"

typedef struct s_trange	t_trange;
typedef struct s_hit_record	t_hit_record;

typedef struct s_quaternion
{
	double				x;
	double				y;
	double				z;
	double				w;
}						t_quaternion;

typedef struct s_sphere
{
	t_vec_three			origin;
	double				radius;
}						t_sphere;

typedef struct s_cylinder
{
	t_vec_three			origin;
	double				radius;
	double				height;
	t_vec_three			axis;
	t_quaternion		q;
}						t_cylinder;

typedef struct s_plane
{
	t_vec_three			origin;
	t_vec_three			normal;
}						t_plane;

bool					hit_sphere(t_trange t_range, void *hittable, t_ray *r,
							t_hit_record *rec);
bool					hit_cylinder(t_trange t_range, void *hittable, t_ray *r,
							t_hit_record *rec);
bool					hit_plane(t_trange t_range, void *hittable, t_ray *r,
							t_hit_record *rec);
t_quaternion			set_quaternion(t_vec_three axis);
bool					set_face_normal(t_ray *r, t_vec_three *outward_normal,
							t_hit_record *rec);

#endif
