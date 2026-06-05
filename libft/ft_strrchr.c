/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:49:31 by mitsato           #+#    #+#             */
/*   Updated: 2025/10/20 22:21:05 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;
	int	i;

	size = ft_strlen(s);
	i = 0;
	if (!*s && (char)c != 0)
		return (0);
	while (*s)
		++s;
	if ((char)c == 0)
		return ((char *)s);
	--s;
	while (size - 1 > i++ && *s != (char)c)
		--s;
	if (!*s || (size == i && *s != (char)c))
		return (0);
	return ((char *)s);
}
