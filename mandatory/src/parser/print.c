/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 00:41:30 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 00:57:21 by keitotak         ###   ########.fr       */
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

void	print_str(char *str)
{
	printf("\n%s\n\n", str);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

void	print_element(t_list *elm_lst)
{
	t_element	*elm;
	int i = 0;
	printf("\n");
	while (elm_lst)
	{
		printf("\nelement:%d\n", i++);
		elm = (t_element *)elm_lst->content;
		printf("size:\t%ld\n", elm->size);
		printf("ID:\t%s\n", (char *)elm->info->content);
		while (elm->info->next)
		{
			printf("info:\t%s\n", (char *)elm->info->next->content);
			elm->info = elm->info->next;
		}
		elm_lst = elm_lst->next;
	}
	printf("\n");
}

void	print_scene(t_scene *scene)
{
	print_amblight(scene->amblight);
	print_camera(scene->camera);
	print_light(scene->light);
	print_objs(scene->objs);
}

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

void	print_sphere(t_sphere_scene *sph)
{
	if (!sph)
		return ;
	print_id("sphere");
	print_coord(sph->crd);
	printf("diameter: %f", sph->diameter);
	print_color(sph->color);
}

void	print_plane(t_plane_scene *pln)
{
	if (!pln)
		return ;
	print_id("plane");
	print_coord(pln->crd);
	print_vector(pln->vec);
	print_color(pln->color);
}

void	print_cylinder(t_cylinder_scene *cyl)
{
	if (!cyl)
		return ;
	print_id("plane");
	print_coord(cyl->crd);
	print_vector(cyl->vec);
	printf("diameter: %f\n", cyl->diameter);
	printf("height: %f\n", cyl->height);
	print_color(cyl->color);
}

void	print_id(char *id_name)
{
	printf("\nelement: %s\n", id_name);
}

void	print_color(t_color color)
{
	printf("color: r=%d g=%d b=%d\n", color.r, color.g, color.b);
}

void	print_coord(t_coord crd)
{
	printf("coord: x=%f y=%f z=%f\n", crd.x, crd.y, crd.z);
}

void	print_vector(t_vector vec)
{
	printf("vector: x=%f y=%f z=%f\n", vec.x, vec.y, vec.z);
}
