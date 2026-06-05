/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/05 19:28:48 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int stop_minirt(void *v_mlxs)
{
	ft_mlx_loop_end(((t_mlxs *)v_mlxs)->mlx);
	return (0);
}

int	key_handler(int keycode, void *v_mlxs)
{
	if (keycode == 0xFF1B)
		ft_mlx_loop_end(((t_mlxs *)v_mlxs)->mlx);
	// printf("%x\n", keycode);
	if ((keycode >= 0xFF51 && keycode <= 0xFF54) || keycode == 0xFFe1)
	{
		int div = keycode - 0xFF51;
		if (div == 0)
			(((t_mlxs *)v_mlxs))->cam->origin.x -= 0.2;
		else if (div == 1)
			(((t_mlxs *)v_mlxs))->cam->origin.z += 0.2;
		else if (div == 2)
			(((t_mlxs *)v_mlxs))->cam->origin.x -= 0.2;
		else if (div == 3)
			(((t_mlxs *)v_mlxs))->cam->origin.z -= 0.2;

		if (keycode == 0xFFe1)
			(((t_mlxs *)v_mlxs))->cam->origin.y -= 0.2;

		view_calc(((t_mlxs *)v_mlxs));
		print(((t_mlxs *)v_mlxs));
	}
	return (0);
}
