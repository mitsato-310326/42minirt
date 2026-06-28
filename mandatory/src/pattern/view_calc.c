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
			r = get_ray((i + 0.5) / (WIDTH - 1), (j + 0.5) / (HEIGHT - 1), *(mlxs->cam));
			pixel_color = vec_three_add(pixel_color, ray_color(&r, mlxs));
			my_pixel_put(mlxs->data, i, j, &pixel_color);
			++i;
		}
		--j;
	}
	return (1);
}
