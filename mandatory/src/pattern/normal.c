/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/28 16:01:16 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "lambertian.h"
#define ambient_color (struct s_vec_three){1, 1, 1}
#define ambient_ratio 0.8

t_vec_three check_light(t_hit_record rec, t_mlxs *mlxs)
{
    t_vec_three direct = (struct s_vec_three){0, 0, 0};
    t_light_list *light = mlxs->light_list;

    while(light)
    {
        t_vec_three to_light = vec_three_neg(light->content->pos, rec.p);
        double dist = vec_three_squared(to_light);
        t_vec_three light_dir = vec_three_mult(to_light, 1/dist);

        t_ray shadow_ray;
        shadow_ray.p_origin = vec_three_add(rec.p, vec_three_mult(rec.normal, 0.001));
        shadow_ray.v_dir = light_dir;

        t_hit_record shadow_rec;
        if (list_hit(&shadow_ray, 0, dist, &shadow_rec, mlxs->hittable_list))
        {
            light = light->next;
            continue;
        }
        double diff = fmax(0.0, dot(rec.normal, light_dir));
        t_vec_three contribution = vec_three_mult(light->content->color, diff * light->content->power);
        direct = vec_three_add(direct, contribution);
        light = light->next;
    }
    return direct;
}

t_vec_three ray_color(t_ray* r, t_mlxs *mlxs)
{
	t_hit_record rec;

    if (!list_hit(r, 0.001, INFINITY, &rec, mlxs->hittable_list))
        return (struct s_vec_three){0, 0, 0};

    t_vec_three object_color = rec.material->albedo;
    t_vec_three ambient = vec_three_mult(vec_three_mult_v(object_color, ambient_color), ambient_ratio);

    return vec_three_add(ambient, check_light(rec, mlxs));
}
