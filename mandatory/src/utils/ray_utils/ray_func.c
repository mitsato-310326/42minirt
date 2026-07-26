/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:52:22 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/26 14:35:45 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "ray_util.h"
#include "vec_util.h"

t_ray	get_ray(double u, double v, t_camera camera)
{
	return ((struct s_ray){camera.origin,
		vec_three_add(vec_three_add(camera.lower_left_corner,
				vec_three_mult(camera.horizontal, u)),
			vec_three_neg(vec_three_mult(camera.vertical, v), camera.origin))});
}

t_vec_three	ray_at(t_ray ray, double t)
{
	t_vec_three	mult;
	t_vec_three	ret;

	mult = vec_three_mult(ray.v_dir, t);
	ret = vec_three_add(ray.p_origin, mult);
	return (ret);
}
