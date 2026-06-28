/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weekend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:14:09 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/28 15:53:53 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_weekend.h"
#include "minirt.h"

double	random_double(void)
{
  PERROR
	return (0.5);
}

// double	random_double_with(double min, double max)
// {
// 	return (min + (max - min) * random_double());
// }

double clamp(double x, double min, double max)
{
  if (x < min) return min;
  if (x > max) return max;
  return x;
}

