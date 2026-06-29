/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:01:00 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 12:11:49 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRINT_H
# define PARSER_PRINT_H

# include "minirt.h"
# include "scene.h"

// print.c
void	print_str(char *str);
void	print_list(t_list *list);
void	print_element(t_list *elm_lst);
void	print_scene(t_scene *scene);

// print_scene.c
void	print_amblight(t_amblight_scene *ambl);
void	print_camera(t_camera_scene *cmr);
void	print_light(t_light_scene *lgt);
void	print_objs(t_list *obj_lst);

// print_objs.c
void	print_sphere(t_sphere_scene *sph);
void	print_plane(t_plane_scene *pln);
void	print_cylinder(t_cylinder_scene *cyl);

// print_utils.c
void	print_id(char *id_name);
void	print_color(t_color color);
void	print_coord(t_coord crd);
void	print_vector(t_vector vec);

#endif
