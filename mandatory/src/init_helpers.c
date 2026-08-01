/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 22:23:25 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/30 00:00:00 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

t_hittable	*create_cylinder_hittable(t_obj_content *content)
{
	t_hittable			*tmp;
	t_cylinder			*cyl;
	t_cylinder_scene	*cyl_sc;

	cyl_sc = (t_cylinder_scene *)content->obj;
	tmp = malloc(sizeof(t_hittable));
	if (tmp == NULL)
		return (NULL);
	tmp->color = cyl_sc->color;
	tmp->hit_fn = &hit_cylinder;
	cyl = malloc(sizeof(t_cylinder));
	if (cyl == NULL)
	{
		free(tmp);
		return (NULL);
	}
	cyl->origin = cyl_sc->crd;
	cyl->axis = cyl_sc->vec;
	cyl->radius = cyl_sc->diameter / 2.0;
	cyl->height = cyl_sc->height;
	cyl->q = set_quaternion(cyl->axis);
	tmp->object_unique_info = cyl;
	return (tmp);
}

t_hittable	*create_sphere_hittable(t_obj_content *content)
{
	t_hittable		*tmp;
	t_sphere		*sph;
	t_sphere_scene	*sph_sc;

	sph_sc = (t_sphere_scene *)content->obj;
	tmp = malloc(sizeof(t_hittable));
	if (tmp == NULL)
		return (NULL);
	sph = malloc(sizeof(t_sphere));
	if (sph == NULL)
	{
		free(tmp);
		return (NULL);
	}
	tmp->color = sph_sc->color;
	tmp->hit_fn = &hit_sphere;
	sph->origin = sph_sc->crd;
	sph->radius = sph_sc->diameter / 2.0;
	tmp->object_unique_info = sph;
	return (tmp);
}

t_hittable	*create_plane_hittable(t_obj_content *content)
{
	t_hittable		*tmp;
	t_plane			*pln;
	t_plane_scene	*pln_sc;

	pln_sc = (t_plane_scene *)content->obj;
	tmp = malloc(sizeof(t_hittable));
	if (tmp == NULL)
		return (NULL);
	pln = malloc(sizeof(t_plane));
	if (pln == NULL)
	{
		free(tmp);
		return (NULL);
	}
	tmp->color = pln_sc->color;
	tmp->hit_fn = &hit_plane;
	pln->normal = pln_sc->vec;
	pln->origin = pln_sc->crd;
	tmp->object_unique_info = pln;
	return (tmp);
}

bool	valid_filename(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	file += len - RTLEN;
	if (ft_strncmp(file, RT, RTLEN + 1) == 0)
		return (true);
	return (false);
}
