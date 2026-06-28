/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/22 20:49:49 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	destroy_minirt(t_mlxs *mlxs)
{
	if (mlxs && mlxs->img)
		mlx_destroy_image(mlxs->mlx, mlxs->img);
	if (mlxs && mlxs->win)
		mlx_destroy_window(mlxs->mlx, mlxs->win);
	if (mlxs)
	{
		ft_mlx_destroy_display(mlxs->mlx);
		free(mlxs->mlx);
		free(mlxs);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlxs	*mlxs;

	if (ac != 2)
	{
		put_error("Invalid args", 0);
		return (EXIT_FAILURE);
	}
	mlxs = init(av[1]);
	if (mlxs == NULL)
		return (1);
	view_calc(mlxs);
	print(mlxs);
	mlx_loop(mlxs->mlx);
	destroy_minirt(mlxs);
	return (0);
}
