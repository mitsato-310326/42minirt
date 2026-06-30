/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 20:54:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/27 16:11:46 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "minirt.h"

typedef struct s_light_scene t_light_scene;

typedef struct s_ambient
{
	t_vec_three color;
	double	power;
}			t_ambient;

t_light_scene *create_lights();

#endif
