/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:09:24 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/29 18:36:29 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_util.h"
#include "ft_weekend.h"

double dot(t_vec_three a, t_vec_three b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec_three unit_vector(t_vec_three v)
{
  return (vec_three_mult(v, 1.0 / vec_three_squared(v)));
}

#define PI 3.14159265

t_vec_three random_in_unit_sphere()
{
  double a = random_double_with(0, 2*PI);
  double z = random_double_with(-1, 1);
  double r = sqrt(1 - z*z);
  return (struct s_vec_three){r * cos(a), r * sin(a), z};
}

t_vec_three random_in_hemisphere(t_vec_three *normal)
{
	t_vec_three in_unit_sphere = random_in_unit_sphere();
	if (dot(in_unit_sphere, *normal) > 0.0)
		return in_unit_sphere;
	else
		return vec_three_mult(in_unit_sphere, -1);
}

t_vec_three reflect(t_vec_three *v, t_vec_three *n)
{
	return vec_three_neg(*v, vec_three_mult(*n, 2.0f * dot(*v,*n)));
}
