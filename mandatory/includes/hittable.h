/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:58:40 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/29 22:01:36 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
#define HITTABLE_H

# include "minirt.h"
# include "material.h"
# include "sphere.h"

typedef struct  s_hit_record
{
    t_vec_three p;
    t_vec_three normal;
    t_material *material;
    double t;
    bool front_face;
}   t_hit_record;

typedef struct s_hittable
{
	t_material * material;
	bool (*hit_fn)(double t_min, double t_max, void *hittable, t_ray *r, t_hit_record *rec);
	void *object_unique_info;
}			t_hittable;

#endif
