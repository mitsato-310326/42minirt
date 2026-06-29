/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:31:53 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 12:03:49 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_UTILS_H
# define SCENE_UTILS_H

# include "minirt.h"

// set_scene.c
t_scene	*set_elm_to_scene(t_scene *scene, t_element *elm);

// create_objs.c
t_sphere_scene		*create_sphere(t_element *elm);
t_plane_scene		*create_plane(t_element *elm);
t_cylinder_scene	*create_cylinder(t_element *elm);

// set_info.c
t_coord				*set_coord(t_coord *crd, char const *str);
t_vector			*set_vector(t_vector *vec, char const *str);
t_color				*set_color(t_color *clr, char const *str);
double				*set_ratio(double *ratio, char *str);
int					*set_fov(int *fov, char const *str);

// fint_utils.c
int					*set_int(int *i, char const *str);
bool				is_int(char const *str);
bool				range_int(int d, int min, int max);

// fdouble_utils.c
double				*set_double(double *f, char *str);
bool				is_double(char const *str);
bool				range_double(double f, double min, double max);

// ft_atod.c
double				ft_atod(char const *str);
bool				is_three_dimential(char const *str);

#endif
