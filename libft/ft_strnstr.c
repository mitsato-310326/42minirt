/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:19:44 by mitsato           #+#    #+#             */
/*   Updated: 2025/10/20 20:48:25 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((len == 0 && !needle))
		return (0);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && haystack[i + j] == needle[j] && i
			+ j < len)
			++j;
		if (i + j == len || !needle[j])
			break ;
		++i;
	}
	if ((!haystack[i] && needle[j] != 0) || (i + j == len && needle[j]))
		return (0);
	return ((char *)haystack + i);
}
