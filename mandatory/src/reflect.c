/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:18:37 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/28 15:53:25 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void reflect(t_hit_record *rec, t_vec_three *attenuation, t_ray *reflected, void *material)
// {
//     t_vec_three reflect_direction = rec->normal;
//     *reflected = (struct s_ray){rec->p, reflect_direction};
//     *attenuation = *(t_vec_three *)material;
// }