/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:39:25 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 00:28:01 by keitotak         ###   ########.fr       */
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
	clr->r = ft_atoi(arr[0]);
	clr->g = ft_atoi(arr[1]);
	clr->b = ft_atoi(arr[2]);
	free_array(arr, 3);
	if (!range_int(clr->r, 0, 255))
		return (NULL);
	if (!range_int(clr->g, 0, 255))
		return (NULL);
	if (!range_int(clr->b, 0, 255))
		return (NULL);
	return (clr);
}

int	*set_fov(int *fov, char const *str)
{
	if (!set_int(fov, str))
		return (NULL);
	if (!range_int(*fov, 0, 180))
		return (NULL);
	return (fov);
}

double	*set_ratio(double *ratio, char *str)
{
	if (!set_double(ratio, str))
		return (NULL);
	if (!range_double(*ratio, 0.0, 1.0))
		return (NULL);
	return (ratio);
}
