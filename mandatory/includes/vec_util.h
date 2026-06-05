/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:32:16 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/29 18:37:06 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_UTIL_H
# define VEC_UTIL_H

# include <math.h>

/*											*/

typedef struct s_vec_three
{
	double	x;
	double	y;
	double	z;
}			t_vec_three;

/*					UTILS					*/

t_vec_three	vec_three_add(t_vec_three a, t_vec_three b);
t_vec_three	vec_three_neg(t_vec_three a, t_vec_three b);
t_vec_three	vec_three_mult(t_vec_three a, double t);
t_vec_three vec_three_mult_v(t_vec_three a, t_vec_three b);
double		vec_three_squared(t_vec_three a);

double		dot(t_vec_three a, t_vec_three b);
t_vec_three unit_vector(t_vec_three v);
t_vec_three random_in_unit_sphere();
t_vec_three random_in_hemisphere(t_vec_three *normal);

t_vec_three reflect(t_vec_three *v, t_vec_three *n);

/*					DEBUG					*/

/*											*/

#endif
