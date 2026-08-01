/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/08/01 12:15:50 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* avoid non-constant macros; use local scene pointer */

bool	shadow_hit(t_ray *r, double t_max, t_hittable_list *top)
{
	t_hit_record	shadow_rec;

	if (list_hit(r, (t_trange){0.001, t_max}, &shadow_rec, top))
		return (true);
	return (false);
}

t_vec_three	check_light(t_hit_record rec, t_mlxs *mlxs)
{
	t_scene		*scene;
	t_vec_three	to_light;
	double		dist;
	t_vec_three	light_dir;
	t_ray		shadow_ray;

	scene = mlxs->scene;
	to_light = vec_three_neg(scene->light->crd, rec.p);
	dist = vec_three_length(to_light);
	light_dir = vec_three_mult(to_light, 1 / dist);
	shadow_ray.p_origin = vec_three_add(rec.p, vec_three_mult(rec.normal,
				0.001));
	shadow_ray.v_dir = light_dir;
	if (shadow_hit(&shadow_ray, dist, mlxs->hittable_list))
		return ((struct s_vec_three){0, 0, 0});
	return (vec_three_mult(scene->light->color, fmax(0.0, dot(rec.normal,
					light_dir)) * scene->light->ratio));
}

t_vec_three	ray_color(t_ray *r, t_mlxs *mlxs)
{
	t_scene			*scene;
	t_hit_record	rec;
	t_vec_three		object_color;
	t_vec_three		ambient;

	scene = mlxs->scene;
	if (!list_hit(r, (t_trange){0.001, INFINITY}, &rec, mlxs->hittable_list))
		return ((struct s_vec_three){0, 0, 0});
	object_color = rec.color;
	ambient = vec_three_mult(vec_three_mult_v(object_color,
				scene->amblight->color), scene->amblight->ratio);
	return (vec_three_add(ambient, vec_three_mult_v(object_color,
				check_light(rec, mlxs))));
}

int	view_calc(t_mlxs *mlxs)
{
	int			i;
	int			j;
	t_vec_three	pixel_color;
	t_ray		r;

	j = HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			pixel_color = (struct s_vec_three){0, 0, 0};
			r = get_ray((i + 0.5) / (WIDTH - 1), (j + 0.5) / (HEIGHT - 1),
					*(mlxs->cam));
			pixel_color = vec_three_add(pixel_color, ray_color(&r, mlxs));
			my_pixel_put(mlxs->data, i, j, &pixel_color);
			++i;
		}
		--j;
	}
	return (1);
}
