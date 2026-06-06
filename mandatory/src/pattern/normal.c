/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:01:23 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/06 16:29:49 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "lambertian.h"

t_vec_three ray_color(t_ray* r, t_hittable_list *world, int depth)
{
	if (depth <= 0)
		return (struct s_vec_three){0, 0, 0};
	t_hit_record rec;

	if (list_hit(r, 0.001, INFINITY, &rec, world))
	{
		t_ray scattered;
		t_vec_three attenuation;
		if (list_scatter(r, &rec, &attenuation, &scattered, rec.material))
			return vec_three_mult_v(attenuation, ray_color(&scattered, world, depth-1));
		return (struct s_vec_three){0, 0, 0};
	}

	t_vec_three unit_direction = unit_vector(r->v_dir);
	double t = 0.5*(unit_direction.y + 1.0);

	t_vec_three color1 = (struct s_vec_three){1.0, 1.0, 1.0};
	t_vec_three color2 = (struct s_vec_three){0.5, 0.7, 1.0};
	return (vec_three_add(vec_three_mult(color1, 1.0 - t), vec_three_mult(color2, t)));
}
