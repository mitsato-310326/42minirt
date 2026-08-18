/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 21:29:44 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 18:16:11 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define NILL '\0'
#define DOT '.'
#define COMMA ','

bool	is_three_dimential(char const *str)
{
	int	comma_count;

	if (str == NULL || *str == '\0')
		return (false);
	comma_count = 0;
	while (*str)
	{
		if (*str == COMMA)
		{
			if (++comma_count > 2 || str == NULL || *(str + 1) == '\0')
				return (false);
		}
		else if (!ft_isdigit((unsigned char)*str) && !ft_issign(*str)
			&& *str != DOT)
			return (false);
		str++;
	}
	return (comma_count == 2);
}

double	ft_atod(char const *str)
{
	double	value;
	double	decimal;
	int		sign;

	sign = 1;
	if (ft_issign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	value = 0.0;
	while (ft_isdigit((unsigned char)*str))
		value = value * 10.0 + (*str++ - '0');
	if (*str == '.')
		str++;
	decimal = 0.1;
	while (ft_isdigit((unsigned char)*str))
	{
		value += (*str++ - '0') * decimal;
		decimal *= 0.1;
	}
	return (sign * value);
}
