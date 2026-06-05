/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:52:59 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/29 18:37:23 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_UTIL_H
# define RAY_UTIL_H

# include "vec_util.h"

typedef struct s_vec_three t_vec_three;

/*											*/

typedef struct s_ray
{
	t_vec_three p_origin;
	t_vec_three v_dir;
}			t_ray;

/*					UTILS					*/

t_vec_three ray_at(t_ray ray, double t);

/*					DEBUG					*/

/*											*/

#endif
