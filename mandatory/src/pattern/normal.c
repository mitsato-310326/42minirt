/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/28 16:37:07 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"
#include "minirt.h"

#define ambient_color (struct s_vec_three){1, 1, 1}
#define ambient_ratio 0.8

t_vec_three	check_light(t_hit_record rec, t_mlxs *mlxs)
{
	t_vec_three		direct;
	t_light_list	*light;
	t_vec_three		to_light;
	double			dist;
	t_vec_three		light_dir;
	t_ray shadow_ray;
	t_hit_record shadow_rec;
	double			diff;
	t_vec_three		contribution;

	direct = (struct s_vec_three){0, 0, 0};
	light = mlxs->light_list;
	while (light)
	{
		to_light = vec_three_neg(light->content->pos, rec.p);
		dist = vec_three_squared(to_light);
		light_dir = vec_three_mult(to_light, 1 / dist);
		shadow_ray.p_origin = vec_three_add(rec.p, vec_three_mult(rec.normal, 0.001));
		shadow_ray.v_dir = light_dir;
		if (list_hit(&shadow_ray, 0, dist, &shadow_rec, mlxs->hittable_list))
		{
			light = light->next;
			continue ;
		}
		diff = fmax(0.0, dot(rec.normal, light_dir));
		contribution = vec_three_mult(light->content->color, diff
				* light->content->power);
		direct = vec_three_add(direct, contribution);
		light = light->next;
	}
	return (direct);
}

t_vec_three	ray_color(t_ray *r, t_mlxs *mlxs)
{
	t_hit_record	rec;
	t_vec_three		object_color;
	t_vec_three		ambient;

	if (!list_hit(r, 0.001, INFINITY, &rec, mlxs->hittable_list))
		return ((struct s_vec_three){0, 0, 0});
	object_color = rec.material->albedo;
	ambient = vec_three_mult(vec_three_mult_v(object_color, ambient_color),
			ambient_ratio);
	return (vec_three_add(ambient, check_light(rec, mlxs)));
}
