/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:55:19 by mitsato           #+#    #+#             */
/*   Updated: 2025/10/20 17:45:38 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (size > 0 && nmemb > 0 && SIZE_MAX / size < nmemb)
		return (NULL);
	dst = malloc(nmemb * size);
	if (!dst)
		return (NULL);
	while (i < nmemb * size && (nmemb != 0 && size != 0))
		dst[i++] = 0;
	return ((void *)dst);
}
