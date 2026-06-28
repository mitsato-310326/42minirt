/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:39:25 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/28 00:37:53 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser_utils.h"
#include "vec_util.h"

t_coord	*set_point(t_coord *pnt, char const *str)
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
	pnt->x = ft_atod(arr[0]);
	pnt->y = ft_atod(arr[1]);
	pnt->z = ft_atod(arr[2]);
	free_array(arr, 3);
	return (pnt);
}

t_vec_three	*set_vector(t_vec_three *vec, char const *str)
{
	vec = set_point(vec, str);
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
