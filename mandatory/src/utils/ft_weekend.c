/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weekend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:14:09 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/05 16:56:47 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_weekend.h"

double	random_double(void)
{
	return (rand() / (2147483647 + 1.0));
}

double	random_double_with(double min, double max)
{
	return (min + (max - min) * random_double());
}

double clamp(double x, double min, double max)
{
  if (x < min) return min;
  if (x > max) return max;
  return x;
}

