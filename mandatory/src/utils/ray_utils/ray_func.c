/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:52:22 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/29 18:40:32 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_util.h"
#include "ray_util.h"

t_vec_three ray_at(t_ray ray, double t)
{
	t_vec_three mult;
	t_vec_three ret;

	mult = vec_three_mult(ray.v_dir, t);
	ret = vec_three_add(ray.p_origin, mult);
	return (ret);
}
