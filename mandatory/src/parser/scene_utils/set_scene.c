/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:24:47 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/28 01:04:32 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_amblight_scene	*set_amblight(t_amblight_scene *ambl, t_element *elm)
{
	if (elm->size != 3)
		return (NULL);
	ambl = (t_amblight_scene *)malloc(sizeof(t_amblight_scene));
	if (ambl == NULL)
		return (NULL);
	if (!set_ratio(&ambl->ratio, ft_lstsearch(elm->info, 1)))
		return (free(ambl), NULL);
	if (!set_color(&ambl->color, ft_lstsearch(elm->info, 2)))
		return (free(ambl), NULL);
	return (ambl);
}

static t_camera_scene	*set_camera(t_camera_scene *cmr, t_element *elm)
{
	if (elm->size != 4)
		return (NULL);
	cmr = (t_camera_scene *)malloc(sizeof(t_camera_scene));
	if (cmr == NULL)
		return (NULL);
	if (!set_point(&cmr->point, ft_lstsearch(elm->info, 1)))
		return (free(cmr), NULL);
	if (!set_vector(&cmr->vec, ft_lstsearch(elm->info, 2)))
		return (free(cmr), NULL);
	if (!set_fov(&cmr->fov, ft_lstsearch(elm->info, 3)))
		return (free(cmr), NULL);
	return (cmr);
}

static t_light_scene	*set_light(t_light_scene *lgt, t_element *elm)
{
	if (elm->size != 4)
		return (NULL);
	lgt = (t_light_scene *)malloc(sizeof(t_light_scene));
	if (lgt == NULL)
		return (NULL);
	if (!set_point(&lgt->point, ft_lstsearch(elm->info, 1)))
		return (free(lgt), NULL);
	if (!set_ratio(&lgt->ratio, ft_lstsearch(elm->info, 2)))
		return (free(lgt), NULL);
	if (!set_color(&lgt->color, ft_lstsearch(elm->info, 3)))
		return (free(lgt), NULL);
	return (lgt);
}

static t_list	*set_object(t_list *obj_lst, t_element *elm)
{
	t_obj_content	*content;
	t_list			*newnode;

	content = (t_obj_content *)malloc(sizeof(t_obj_content));
	if (content == NULL)
		return (NULL);
	content->obj = NULL;
	if (elm->id == SPHERE)
		content->obj = create_sphere(elm);
	else if (elm->id == PLANE)
		content->obj = create_plane(elm);
	else if (elm->id == CYLINDER)
		content->obj = create_cylinder(elm);
	if (content->obj == NULL)
	{
		free(content);
		return (NULL);
	}
	content->id = elm->id;
	newnode = ft_lstnew(content);
	if (newnode == NULL)
	{
		free(content->obj);
		free(content);
		return (NULL);
	}
	ft_lstadd_back(&obj_lst, newnode);
	return (obj_lst);
}

t_scene	*set_elm_to_scene(t_scene *scene, t_element *elm)
{
	if (elm->id == AMBIENT)
	{
		scene->amblight = set_amblight(scene->amblight, elm);
		if (scene->amblight == NULL)
			return (NULL);
	}
	else if (elm->id == CAMERA)
	{
		scene->camera = set_camera(scene->camera, elm);
		if (scene->camera == NULL)
			return (NULL);
	}
	else if (elm->id == LIGHT)
	{
		scene->light = set_light(scene->light, elm);
		if (scene->light == NULL)
			return (NULL);
	}
	else
	{
		scene->objs = set_object(scene->objs, elm);
		if (scene->objs == NULL)
			return (NULL);
	}
	return (scene);
}
