/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:00:23 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 12:00:34 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_print.h"

void	print_id(char *id_name)
{
	printf("\nelement: %s\n", id_name);
}

void	print_color(t_color color)
{
	printf("color: r=%f g=%f b=%f\n", color.x, color.y, color.z);
}

void	print_coord(t_coord crd)
{
	printf("coord: x=%f y=%f z=%f\n", crd.x, crd.y, crd.z);
}

void	print_vector(t_vector vec)
{
	printf("vector: x=%f y=%f z=%f\n", vec.x, vec.y, vec.z);
}
