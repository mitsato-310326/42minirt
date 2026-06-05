/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:27:19 by mitsato           #+#    #+#             */
/*   Updated: 2025/10/16 15:25:03 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	long long	lsize;
	size_t		dst_len;

	i = 0;
	lsize = dstsize;
	if (lsize < 0)
		dstsize = (lsize + ULONG_MAX);
	dst_len = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize == 1 && *dst != '\0')
		return (ft_strlen(src) + 1);
	while (dst_len > i && i < dstsize)
		++i;
	while ((ft_strlen(src) > (i - dst_len)) && i < dstsize - 1)
	{
		dst[i] = src[i - dst_len];
		++i;
	}
	if (dstsize > dst_len)
		dst[i] = '\0';
	if (dstsize < dst_len)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + dst_len);
}
