/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:30:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/28 16:06:53 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void my_pixel_put(char *data, int x, int y, t_vec_three *color)
{
	double ir = color->x;
	double ig = color->y;
	double ib = color->z;

	ir = sqrt(ir);
	ig = sqrt(ig);
	ib = sqrt(ib);

	int r = (256 * clamp(ir, 0.0, 0.999));
	int g = (256 * clamp(ig, 0.0, 0.999));
	int b = (256 * clamp(ib, 0.0, 0.999));

	int offset;

	int ry = HEIGHT - y;

	offset = (ry * WIDTH + x) * 4;
	data[offset + 0] = b & 0xFF;
	data[offset + 1] = g & 0xFF;
	data[offset + 2] = r & 0xFF;
}

bool print(t_mlxs *mlxs)
{
	mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, 0, 0);

	return (true);
}
