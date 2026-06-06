/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/06 16:52:55 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYSICS_H
# define PHYSICS_H

#include "hittable.h"
#include "minirt.h"

typedef struct s_sphere
{
	t_vec_three origin;
	double	radius;
}			t_sphere;

typedef struct s_cylinder
{
	t_vec_three origin;
	double	radius;
	double	height;
	t_vec_three axis;
}			t_cylinder;

bool hit_sphere(double t_min, double t_max, void *hittable, t_ray *r, t_hit_record *rec);
bool hit_cylinder(double t_min, double t_max, void *hittable, t_ray *r, t_hit_record *rec);

#endif
