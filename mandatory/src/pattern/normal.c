/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/27 16:25:26 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "lambertian.h"
#define ambient_color (struct s_vec_three){1, 1, 1}
#define ambient_ratio 0.5

t_vec_three ray_color(t_ray* r, t_hittable_list *world, t_light_list light, int depth)
{
	(void)depth;
	t_hit_record rec;

    if (!list_hit(r, 0.001, INFINITY, &rec, world))
        return (struct s_vec_three){0, 0, 0}; // 背景は黒

    t_vec_three object_color = rec.material->albedo; // attenuationだったもの

    // ambient
    t_vec_three ambient = vec_three_mult(vec_three_mult_v(object_color, ambient_color), ambient_ratio);

    // direct light (shadow ray込み)
    // t_vec_three direct = compute_direct_light(&rec, lights, n_lights, world);
    t_vec_three direct = (struct s_vec_three){0, 0, 0};
    // direct = vec_three_mult_v(object_color, direct);

    return vec_three_add(ambient, direct);
}
