/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_calc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/04 15:37:14 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define ambient_color (struct s_vec_three){1, 1, 1}
#define ambient_ratio 0.0001
#define scenespath mlxs->scene

//ここはlightを変える都合で後回し
t_vec_three	check_light(t_hit_record rec, t_mlxs *mlxs)
{
	t_vec_three		direct;
	t_vec_three		to_light;
	double			dist;
	t_vec_three		light_dir;
	t_ray shadow_ray;
	t_hit_record shadow_rec;
	double			diff;


	direct = (struct s_vec_three){0, 0, 0};
	to_light = vec_three_neg(scenespath->light->crd, rec.p);
	dist = vec_three_length(to_light);
	light_dir = vec_three_mult(to_light, 1 / dist);
	shadow_ray.p_origin = vec_three_add(rec.p, vec_three_mult(rec.normal, 0.001));
	shadow_ray.v_dir = light_dir;
	if (list_hit(&shadow_ray, 0, dist, &shadow_rec, mlxs->hittable_list))
	{
		return (direct);
	}
	diff = fmax(0.0, dot(rec.normal, light_dir));
	direct = vec_three_add(direct, vec_three_mult(scenespath->light->color, diff
			* scenespath->light->ratio));
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
	ambient = vec_three_mult(vec_three_mult_v(object_color, scenespath->amblight->color),
			scenespath->amblight->ratio);
	return (vec_three_add(ambient, check_light(rec, mlxs)));
}

int	view_calc(t_mlxs *mlxs)
{
	int			i;
	int			j;
	t_vec_three	pixel_color;
	t_ray		r;

	
	// sceneslight->color.x = 1;
	// sceneslight->color.y = 1;
	// sceneslight->color.z = 0.5;

	print_scene(mlxs->scene);

	j = HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			pixel_color = (struct s_vec_three){0, 0, 0};
			r = get_ray((i + 0.5) / (WIDTH - 1), (j + 0.5) / (HEIGHT - 1), *(mlxs->cam));
			pixel_color = vec_three_add(pixel_color, ray_color(&r, mlxs));
			my_pixel_put(mlxs->data, i, j, &pixel_color);
			++i;
		}
		--j;
	}
	return (1);
}
