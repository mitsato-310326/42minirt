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

# include "material.h"
# include "minirt.h"

typedef struct s_trange t_trange;

typedef struct s_hit_record
{
	t_vec_three	p;
	t_vec_three	normal;
	t_vec_three	color;
	double		t;
	bool		front_face;
}				t_hit_record;

typedef struct s_hittable
{
	t_vec_three	color;
	bool		(*hit_fn)(t_trange t_range, void *hittable, t_ray *r,
				t_hit_record *rec);
	void		*object_unique_info;
}				t_hittable;

#endif
