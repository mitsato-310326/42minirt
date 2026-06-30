/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/04/12 15:09:14 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/minirt.h"

void	ft_mlx_destroy_display(void *mlx)
{
	switch (OS)
	{
	case MAC_OS:
		(void)mlx;
		return ;
	case LINUX_OS:
		mlx_destroy_display(mlx);
		return ;
	}
}

void	ft_mlx_loop_end(void *mlx)
{
	switch (OS)
	{
	case MAC_OS:
		(void)mlx;
		return ;
	case LINUX_OS:
		mlx_loop_end(mlx);
		return ;
	}
}