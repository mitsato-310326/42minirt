/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:40:08 by mitsato           #+#    #+#             */
/*   Updated: 2026/03/26 21:05:15 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim(char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			break ;
		++i;
	}
	if (set[i])
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;

	i = 0;
	if (!set)
		return (ft_strdup(""));
	while (is_trim(*s1, set))
		++s1;
	while (s1[i])
		++i;
	--i;
	while (is_trim(s1[i], set) && i > -1)
		--i;
	++i;
	return (ft_strndup((char *)s1, i));
}
