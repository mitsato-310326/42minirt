/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:44:24 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/25 15:52:42 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	arrlen(char **array)
{
	size_t	size;

	size = 0;
	while (*array++)
		size++;
	return (size);
}

void	print_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		printf("line%2ld: %s\n", i, arr[i]);
		i++;
	}
}
