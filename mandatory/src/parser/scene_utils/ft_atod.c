/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 21:29:44 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/28 00:07:59 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define NILL '\0'
#define DOT '.'
#define COMMA ','

bool	is_three_dimential(char const *str)
{
	int	dot_cnt;

	dot_cnt = 0;
	while (*str)
	{
		if (ft_isdigit(*str) || ft_issign(*str) || *str == DOT)
			str++;
		else if (*str == COMMA)
		{
			if (!ft_isdigit(*(str + 1)))
				return (false);
			dot_cnt++;
			str++;
		}
		else
			return (false);
	}
	if (dot_cnt != 2)
		return (false);
	return (true);
}

double	ft_atod(char const *str)
{
	int		sg;
	double	in;
	double	fr;

	sg = 1;
	fr = 0;
	if (ft_issign(*str))
	{
		if (*str == '-')
			sg *= -1;
		str++;
	}
	in = (double)ft_atoi(str);
	str = ft_strchr(str, '.');
	if (str == NULL)
		return ((double)in);
	str++;
	fr = (double)ft_atoi(str);
	fr /= pow(10.0, (double)ft_strlen(str));
	return (sg * (in + fr));
}
