/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/08/06 18:35:06 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_mlxs	*mlxs;

	if (ac != 2)
	{
		put_error("Invalid args\n", 0);
		return (EXIT_FAILURE);
	}
	mlxs = init(av[1]);
	if (mlxs == NULL)
		return (1);
	view_calc(mlxs);
	print(mlxs);
	mlx_loop(mlxs->mlx);
	destroy_minirt(mlxs);
	return (EXIT_SUCCESS);
}
