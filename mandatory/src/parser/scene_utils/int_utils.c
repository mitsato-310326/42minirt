/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:07:42 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/27 22:35:11 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define MAX_INT_STRLEN 11
#define MAX_INT_DIGITS 10

bool	range_int(int d, int min, int max)
{
	return (min <= d && d <= max);
}

static bool	is_valid_int_str(char const *str)
{
	int	digit_count;

	if (str == NULL || *str == '\0')
		return (false);
	if (ft_strlen(str) > MAX_INT_STRLEN)
		return (false);
	if (*str == '+' || *str == '-')
		str++;
	digit_count = 0;
	while (*str)
	{
		if (ft_isdigit((unsigned char)*str))
			digit_count++;
		else
			return (false);
		str++;
	}
	if (digit_count == 0 || digit_count > MAX_INT_DIGITS)
		return (false);
	return (true);
}

bool	is_int(char const *str)
{
	return (is_valid_int_str(str));
}

int	*set_int(int *i, char const *str)
{
	if (!is_valid_int_str(str))
		return (NULL);
	*i = ft_atoi(str);
	return (i);
}
