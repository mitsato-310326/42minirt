/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:39:25 by keitotak          #+#    #+#             */
/*   Updated: 2026/07/26 14:36:49 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser_utils.h"
#include "vec_util.h"

t_coord	*set_coord(t_coord *crd, char const *str)
{
	char	**arr;

	if (!is_three_dimential(str))
		return (NULL);
	arr = ft_split(str, ',');
	if (arr == NULL)
		return (NULL);
	if (!is_double(arr[0]) || !is_double(arr[1]) || !is_double(arr[2]))
	{
		free_array(arr, 3);
		return (NULL);
	}
	crd->x = ft_atod(arr[0]);
	crd->y = ft_atod(arr[1]);
	crd->z = ft_atod(arr[2]);
	free_array(arr, 3);
	return (crd);
}

t_vector	*set_vector(t_vector *vec, char const *str)
{
	vec = set_coord(vec, str);
	if (vec == NULL)
		return (NULL);
	if (!range_double(vec->x, -1.0, 1.0))
		return (NULL);
	if (!range_double(vec->y, -1.0, 1.0))
		return (NULL);
	if (!range_double(vec->z, -1.0, 1.0))
		return (NULL);
	if (vec->x == 0.0 && vec->y == 0.0 && vec->z == 0.0)
		return (NULL);
	return (vec);
}

static bool	check_color(int r, int g, int b)
{
	if (!range_int(r, 0, 255))
		return (false);
	if (!range_int(g, 0, 255))
		return (false);
	if (!range_int(b, 0, 255))
		return (false);
	return (true);
}

t_color	*set_color(t_color *clr, char const *str)
{
	char	**arr;
	int		r;
	int		g;
	int		b;

	if (!is_three_dimential(str))
		return (NULL);
	arr = ft_split(str, ',');
	if (arr == NULL)
		return (NULL);
	if (!set_int(&r, arr[0]) || !set_int(&g, arr[1]) || !set_int(&b, arr[2]))
	{
		free_array(arr, 3);
		return (NULL);
	}
	free_array(arr, 3);
	if (!check_color(r, g, b))
		return (NULL);
	clr->x = r / 255.0;
	clr->y = g / 255.0;
	clr->z = b / 255.0;
	return (clr);
}

double	*set_ratio(double *ratio, char *str)
{
	if (!set_double(ratio, str))
		return (NULL);
	if (!range_double(*ratio, 0.0, 1.0))
		return (NULL);
	return (ratio);
}
