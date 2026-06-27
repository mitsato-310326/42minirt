/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:01:27 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/27 22:33:52 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define MAX_DOUBLE_STRLEN 19
#define MAX_DOUBLE_DIGITS 17

bool	range_double(double f, double min, double max)
{
	return (min <= f && f <= max);
}

static bool	iter_valid_double_str(char const *str)
{
	int	dot_count;
	int	digit_count;

	dot_count = 0;
	digit_count = 0;
	while (*str)
	{
		if (*str == '.')
		{
			if (dot_count++ > 0)
				return (false);
		}
		else if (ft_isdigit((unsigned char)*str))
			digit_count++;
		else
			return (false);
		str++;
	}
	if (digit_count == 0 || digit_count > MAX_DOUBLE_DIGITS)
		return (false);
	return (true);
}

static bool	is_valid_double_str(char const *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	if (ft_strlen(str) > MAX_DOUBLE_STRLEN)
		return (false);
	if (*str == '+' || *str == '-')
		str++;
	if (!iter_valid_double_str(str))
		return (false);
	return (true);
}

bool	is_double(char const *str)
{
	return (is_valid_double_str(str));
}

double	*set_double(double *f, char *str)
{
	if (!is_double(str))
		return (NULL);
	*f = ft_atod(str);
	return (f);
}
