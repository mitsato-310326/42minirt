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
	return (vec);
}

bool	check_color(t_color *clr, int r, int g, int b)
{
	clr->x = r / 255.0;
	clr->y = g / 255.0;
	clr->z = b / 255.0;
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

	if (!is_three_dimential(str))
		return (NULL);
	arr = ft_split(str, ',');
	if (arr == NULL)
		return (NULL);
	if (!is_int(arr[0]) || !is_int(arr[1]) || !is_int(arr[2]))
	{
		free_array(arr, 3);
		return (NULL);
	}
	if (!check_color(clr, ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2])))
		return (free_array(arr, 3), NULL);
	free_array(arr, 3);
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
