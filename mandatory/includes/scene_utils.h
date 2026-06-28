/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:31:53 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/28 15:13:39 by keitotak         ###   ########.fr       */
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
t_coord				*set_point(t_coord *pnt, char const *str);
t_vec_three			*set_vector(t_vec_three *vec, char const *str);
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

// print_scene.c
void				print_scene(t_scene *scene);
void				print_amblight(t_amblight_scene *ambl);
void				print_camera(t_camera_scene *cmr);
void				print_light(t_light_scene *lgt);
void				print_objs(t_list *obj_lst);
void				print_sphere(t_sphere_scene *sph);
void				print_plane(t_plane_scene *pln);
void				print_cylinder(t_cylinder_scene *cyl);
void				print_point(t_coord point);
void				print_vector(t_vec_three vec);
void				print_color(t_color color);

#endif
