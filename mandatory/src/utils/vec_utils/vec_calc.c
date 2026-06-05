/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:09:24 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/29 21:46:50 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_util.h"


t_vec_three vec_three_add(t_vec_three a, t_vec_three b)
{
	return (struct s_vec_three){a.x + b.x, a.y + b.y, a.z + b.z};
}

t_vec_three vec_three_neg(t_vec_three a, t_vec_three b)
{
	return (struct s_vec_three){a.x - b.x, a.y - b.y, a.z - b.z};
}

//dev: vec_three_mult( arg1 , 1 / t );
t_vec_three vec_three_mult(t_vec_three a, double t)
{
	return (struct s_vec_three){a.x * t, a.y * t, a.z * t};
}

t_vec_three vec_three_mult_v(t_vec_three a, t_vec_three b)
{
	return (struct s_vec_three){a.x * b.x, a.y * b.y, a.z * b.z};
}

double vec_three_squared(t_vec_three a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z *a.z));
}
