/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:09:27 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 12:00:08 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_amblight(t_amblight_scene *ambl);
void	print_camera(t_camera_scene *cmr);
void	print_light(t_light_scene *lgt);
void	print_objs(t_list *obj_lst);
void	print_sphere(t_sphere_scene *sph);
void	print_plane(t_plane_scene *pln);
void	print_cylinder(t_cylinder_scene *cyl);
void	print_id(char *id_name);
void	print_color(t_color color);
void	print_coord(t_coord crd);
void	print_vector(t_vector vec);

void	print_amblight(t_amblight_scene *ambl)
{
	if (!ambl)
		return ;
	print_id("amblight");
	printf("ratio: %f\n", ambl->ratio);
	print_color(ambl->color);
}

void	print_camera(t_camera_scene *cmr)
{
	if (!cmr)
		return ;
	print_id("camera");
	print_coord(cmr->crd);
	print_vector(cmr->vec);
	printf("FOV: %d\n", cmr->fov);
}

void	print_light(t_light_scene *lgt)
{
	if (!lgt)
		return ;
	print_id("light");
	print_coord(lgt->crd);
	printf("ratio: %f\n", lgt->ratio);
	print_color(lgt->color);
}

void	print_objs(t_list *obj_lst)
{
	t_obj_content	*content;

	while (obj_lst)
	{
		content = (t_obj_content *)obj_lst->content;
		if (content->id == SPHERE)
			print_sphere(content->obj);
		if (content->id == PLANE)
			print_plane(content->obj);
		if (content->id == CYLINDER)
			print_cylinder(content->obj);
		obj_lst = obj_lst->next;
	}
}
