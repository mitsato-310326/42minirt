/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:10:33 by mitsato           #+#    #+#             */
/*   Updated: 2025/11/12 22:58:47 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		left_len;
	int		right_len;
	char	*dst;

	i = 0;
	left_len = ft_strlen(s1);
	right_len = ft_strlen(s2);
	dst = malloc((left_len + right_len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < left_len)
	{
		dst[i] = s1[i];
		++i;
	}
	while (i < left_len + right_len)
	{
		dst[i] = s2[i - left_len];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}
