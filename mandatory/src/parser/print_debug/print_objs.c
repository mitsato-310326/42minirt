/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:59:37 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 11:59:53 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_print.h"

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
