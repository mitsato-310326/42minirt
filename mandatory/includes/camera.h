/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:32:16 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/26 14:38:20 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "minirt.h"
# include "ray_util.h"
# include "scene.h"
# include "vec_util.h"

typedef struct s_vec_three	t_vec_three;
typedef struct s_ray		t_ray;

typedef struct s_camera
{
	t_vec_three				origin;
	t_vec_three				lower_left_corner;
	t_vec_three				horizontal;
	t_vec_three				vertical;
}							t_camera;

t_camera					*init_camera(t_camera_scene *camera);
t_ray						get_ray(double u, double v, t_camera camera);

#endif
