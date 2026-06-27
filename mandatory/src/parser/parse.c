/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:59:28 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/28 01:07:49 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "scene.h"
#include "vec_util.h"

void	print_id(char *id_name)
{
	printf("\nelement: %s\n", id_name);
}

void	print_color(t_color color)
{
	printf("color: r=%d g=%d b=%d\n", color.r, color.g, color.b);
}

void	print_point(t_coord point)
{
	printf("point: x=%f y=%f z=%f\n", point.x, point.y, point.z);
}

void	print_vector(t_vec_three vec)
{
	printf("vector: x=%f y=%f z=%f\n", vec.x, vec.y, vec.z);
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
	print_point(cmr->point);
	print_vector(cmr->vec);
	printf("FOV: %d\n", cmr->fov);
}

void	print_light(t_light_scene *lgt)
{
	if (!lgt)
		return ;
	print_id("light");
	print_point(lgt->point);
	printf("ratio: %f\n", lgt->ratio);
	print_color(lgt->color);
}

void	print_sphere(t_sphere_scene *sph)
{
	if (!sph)
		return ;
	print_id("sphere");
	print_point(sph->center);
	printf("diameter: %f", sph->diameter);
	print_color(sph->color);
}

void	print_plane(t_plane_scene *pln)
{
	if (!pln)
		return ;
	print_id("plane");
	print_point(pln->point);
	print_vector(pln->vec);
	print_color(pln->color);
}

void	print_cylinder(t_cylinder_scene *cyl)
{
	if (!cyl)
		return ;
	print_id("plane");
	print_point(cyl->center);
	print_vector(cyl->vec);
	printf("diameter: %f\n", cyl->diameter);
	printf("height: %f\n", cyl->height);
	print_color(cyl->color);
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

void	print_scene(t_scene *scene)
{
	print_amblight(scene->amblight);
	print_camera(scene->camera);
	print_light(scene->light);
	print_objs(scene->objs);
}

t_scene	*parse(char *file)
{
	char	*str;
	t_list	*lines;
	t_list	*elements;
	t_scene		*scene;

	str = read_str(file);
	if (str == NULL)
		return (NULL);
//	printf("%s\n", str);
	lines = get_list(str, "\n");
	if (lines == NULL)
	{
		free(str);
		return (NULL);
	}
	free(str);
//	print_list(lines);
	elements = get_elements(lines);
	if (elements == NULL)
	{
		ft_lstclear(&lines, free);
		return (NULL);
	}
	ft_lstclear(&lines, free);
//	print_element(elements);
	scene = create_scene(elements);
	if (scene == NULL)
	{
		ft_lstclear(&elements, delete_element);
		return (NULL);
	}
	ft_lstclear(&elements, delete_element);
	print_scene(scene);
	return (scene);
}

