/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:12:47 by mitsato           #+#    #+#             */
/*   Updated: 2026/03/26 21:02:45 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	no_malloc(char **line, char *mallocedline)
{
	if (!mallocedline)
		return (1);
	*line = mallocedline;
	return (0);
}

char	*strfjoin(char *left, char *right)
{
	int		i;
	int		l_len;
	int		r_len;
	char	*dst;

	i = -1;
	if (!left || !right)
		return (NULL);
	l_len = ft_strlen_char(left, '\0');
	r_len = ft_strlen_char(right, '\0');
	if (no_malloc(&dst, malloc((l_len + r_len + 1) * sizeof(char))))
		return (NULL);
	while (++i < l_len)
		dst[i] = left[i];
	--i;
	while (++i < l_len + r_len)
		dst[i] = right[i - l_len];
	dst[i] = '\0';
	free(left);
	free(right);
	return (dst);
}

int	reload_line(int *readsize, int *start, char *src, int *i)
{
	if (*readsize >= 0)
	{
		src[*readsize] = '\0';
		*start = 0;
		*i = 0;
		return (0);
	}
	return (1);
}

int	read_check(int *readsize, char *src, int fd, char *r_line)
{
	if (*readsize == -1)
	{
		free(src);
		return (1);
	}
	*readsize = read(fd, src, BUFFER_SIZE);
	if (*readsize == -1)
	{
		free(src);
		free(r_line);
		r_line = NULL;
	}
	return (1);
}
