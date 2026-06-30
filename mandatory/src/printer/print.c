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

void	my_pixel_put(char *data, int x, int y, t_vec_three *color)
{
	int		r;
	int		g;
	int		b;
	int		offset;

	r = (256 * clamp(sqrt(color->x), 0.0, 0.999));
	g = (256 * clamp(sqrt(color->y), 0.0, 0.999));
	b = (256 * clamp(sqrt(color->z), 0.0, 0.999));
	offset = ((HEIGHT - y) * WIDTH + x) * 4;
	data[offset + 0] = b & 0xFF;
	data[offset + 1] = g & 0xFF;
	data[offset + 2] = r & 0xFF;
}

//voidでよさそう
bool	print(t_mlxs *mlxs)
{
	mlx_put_image_to_window(mlxs->mlx, mlxs->win, mlxs->img, 0, 0);
	return (true);
}
