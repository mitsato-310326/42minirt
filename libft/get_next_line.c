/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:50:15 by mitsato           #+#    #+#             */
/*   Updated: 2025/11/13 01:06:24 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	check_src_end(int i, int start, int readsize, char *src)
{
	if (i + start + 1 == readsize)
		return ('\0');
	return (*src);
}

int	ft_strlen_char(char *src, char s)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != s)
		++i;
	return (i);
}

char	*find_end(int *start, int *readsize, char *src, int fd)
{
	int		i;
	char	*r_line;

	i = 0;
	if (no_malloc(&r_line, ft_strndup("\0", 0)))
		return (NULL);
	while (i + *start <= *readsize && *src)
	{
		i += ft_strlen_char(src + *start, '\n');
		if (no_malloc(&r_line, strfjoin(r_line, ft_strndup(src + *start, i
						+ 1))))
			return (NULL);
		if (src[i + *start] == '\n')
			break ;
		if (i + *start == *readsize && read_check(readsize, src, fd, r_line)
			&& reload_line(readsize, start, src, &i))
			return (r_line);
	}
	*start += i + 1;
	return (r_line);
}

char	*set_r_line(int *start, int *readsize, char *src, int fd)
{
	char	*r_line;

	r_line = find_end(start, readsize, src, fd);
	if (!r_line || *readsize == -1)
		return (NULL);
	return (r_line);
}

char	*get_next_line(int fd)
{
	static char	*src;
	static int	start;
	static int	readsize;

	if (readsize == -1 && src)
		src = NULL;
	if ((!src || (src && !src[start])))
	{
		if (!src)
			src = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
		if (!src)
			return (NULL);
		readsize = read(fd, src, BUFFER_SIZE);
		if (readsize == -1 && read_check(&readsize, src, fd, NULL))
			return (NULL);
		src[readsize] = '\0';
		start = 0;
	}
	if (readsize == 0)
	{
		free(src);
		src = NULL;
		return (NULL);
	}
	return (set_r_line(&start, &readsize, src, fd));
}
