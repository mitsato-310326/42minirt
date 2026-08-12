/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 02:23:28 by keitotak          #+#    #+#             */
/*   Updated: 2026/08/01 19:15:24 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "parser.h"
#include "scene.h"

static void	init_scene(t_scene *scene)
{
	scene->amblight = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->objs = NULL;
}

void	delete_obj_content(void *p)
{
	t_obj_content	*content;

	if (p == NULL)
		return ;
	content = (t_obj_content *)p;
	if (content->obj != NULL)
		free(content->obj);
	free(content);
}

void	scene_clear(t_scene *scene)
{
	if (scene == NULL)
		return ;
	if (scene->amblight)
		free(scene->amblight);
	if (scene->camera)
		free(scene->camera);
	if (scene->light)
		free(scene->light);
	if (scene->objs)
		ft_lstclear(&scene->objs, delete_obj_content);
	free(scene);
}

t_scene	*create_scene(t_list *elm_lst)
{
	t_scene		*scene;
	t_element	*elm;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (scene == NULL)
		return (put_error("malloc", 1), NULL);
	init_scene(scene);
	while (elm_lst)
	{
		elm = (t_element *)elm_lst->content;
		if (set_elm_to_scene(scene, elm) == NULL)
		{
			scene_clear(scene);
			return (NULL);
		}
		elm_lst = elm_lst->next;
	}
	if (!scene->amblight || !scene->camera || !scene->light)
	{
		put_error("ambient lighting, camera, and light are required.\n", false);
		scene_clear(scene);
		return (NULL);
	}
	return (scene);
}
