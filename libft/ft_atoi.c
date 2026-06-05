/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:29:35 by mitsato           #+#    #+#             */
/*   Updated: 2025/10/20 22:25:55 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char look)
{
	return (look == ' ' || look == '\f' || look == '\n' || look == '\r'
		|| look == '\t' || look == '\v');
}

static int	ft_issign(char look)
{
	return (look == '+' || look == '-');
}

static int	ft_chartoint(const char *str, int sign)
{
	long long	pos;
	long long	neg;

	pos = 0;
	neg = 0;
	if (sign == -1 && *str && (*str >= '0' && *str <= '9'))
	{
		neg = -(*(str++) - '0');
		while (*str && (*str >= '0' && *str <= '9'))
		{
			if (neg * 10 + 1 < (long long)((LONG_MIN + (*str - '0'))))
				return ((int)LONG_MIN);
			neg = (neg * 10 - (*(str++) - '0'));
		}
		return (neg);
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (pos > (long long)((LONG_MAX - (*str - '0')) / 10))
			return ((int)LONG_MAX);
		pos = (pos * 10 + (*(str++) - '0'));
	}
	return (pos);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	value;

	value = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		++nptr;
	if (ft_issign(*nptr))
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	value = ft_chartoint(nptr, sign);
	return (value);
}
