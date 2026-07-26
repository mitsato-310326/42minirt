/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:14:09 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/26 14:35:54 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_weekend.h"
#include "minirt.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}
