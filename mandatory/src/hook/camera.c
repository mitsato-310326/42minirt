/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:42:08 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/05 19:26:54 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "camera.h"


t_ray get_ray(double u, double v, t_camera camera)
{
    // ENTRY("get_ray");
	return (struct s_ray){camera.origin, vec_three_add(vec_three_add(camera.lower_left_corner, vec_three_mult(camera.horizontal, u)), vec_three_neg(vec_three_mult(camera.vertical, v), camera.origin))};
}
