/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:09:24 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/28 15:54:32 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_weekend.h"
#include "vec_util.h"

double	dot(t_vec_three a, t_vec_three b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec_three	unit_vector(t_vec_three v)
{
	return (vec_three_mult(v, 1.0 / vec_three_length(v)));
}

t_vec_three	cross(t_vec_three a, t_vec_three b)
{
	return ((t_vec_three){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x
		* b.y - a.y * b.x});
}
