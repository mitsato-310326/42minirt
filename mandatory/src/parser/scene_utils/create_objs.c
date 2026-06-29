/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:27:11 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 00:31:26 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere_scene	*create_sphere(t_element *elm)
{
	t_sphere_scene	*sph;

	if (elm->size != 4)
		return (NULL);
	sph = (t_sphere_scene *)malloc(sizeof(t_sphere_scene));
	if (sph == NULL)
		return (NULL);
	if (!set_coord(&sph->crd, ft_lstsearch(elm->info, 1)))
		return (free(sph), NULL);
	if (!set_double(&sph->diameter, ft_lstsearch(elm->info, 2)))
		return (free(sph), NULL);
	if (!set_color(&sph->color, ft_lstsearch(elm->info, 3)))
		return (free(sph), NULL);
	return (sph);
}

t_plane_scene	*create_plane(t_element *elm)
{
	t_plane_scene	*pln;

	if (elm->size != 4)
		return (NULL);
	pln = (t_plane_scene *)malloc(sizeof(t_plane_scene));
	if (pln == NULL)
		return (NULL);
	if (!set_coord(&pln->crd, ft_lstsearch(elm->info, 1)))
		return (free(pln), NULL);
	if (!set_vector(&pln->vec, ft_lstsearch(elm->info, 2)))
		return (free(pln), NULL);
	if (!set_color(&pln->color, ft_lstsearch(elm->info, 3)))
		return (free(pln), NULL);
	return (pln);
}

t_cylinder_scene	*create_cylinder(t_element *elm)
{
	t_cylinder_scene	*cyl;

	if (elm->size != 6)
		return (NULL);
	cyl = (t_cylinder_scene *)malloc(sizeof(t_cylinder_scene));
	if (cyl == NULL)
		return (NULL);
	if (!set_coord(&cyl->crd, ft_lstsearch(elm->info, 1)))
		return (free(cyl), NULL);
	if (!set_vector(&cyl->vec, ft_lstsearch(elm->info, 2)))
		return (free(cyl), NULL);
	if (!set_double(&cyl->diameter, ft_lstsearch(elm->info, 3)))
		return (free(cyl), NULL);
	if (!set_double(&cyl->height, ft_lstsearch(elm->info, 4)))
		return (free(cyl), NULL);
	if (!set_color(&cyl->color, ft_lstsearch(elm->info, 5)))
		return (free(cyl), NULL);
	return (cyl);
}
