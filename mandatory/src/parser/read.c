/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 09:38:48 by keitotak          #+#    #+#             */
/*   Updated: 2026/08/11 15:51:46 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	valid_char(int c)
{
	if (ft_isspace(c))
		return (true);
	if (ft_isalnum(c))
		return (true);
	if (ft_issign(c))
		return (true);
	if (c == '.' || c == ',')
		return (true);
	return (false);
}

static bool	valid_str(char *str)
{
	while (*str)
	{
		if (!valid_char(*str))
			return (false);
		str++;
	}
	return (true);
}

static char	*append_buf(char *str, char *buf, size_t read_count)
{
	size_t	old_len;
	size_t	new_size;
	char	*new_str;

	old_len = ft_strlen(str);
	if (read_count > SIZE_MAX - old_len - 1)
		return (put_error(ERR_ALLOC, false), free(str), NULL);
	new_size = old_len + read_count + 1;
	new_str = ft_realloc(str, new_size);
	if (new_str == NULL)
		return (put_error(ERR_ALLOC, false), free(str), NULL);
	str = new_str;
	ft_strlcat(str, buf, new_size);
	return (str);
}

#define ERR_INVSTR "invalid strings in the scene file.\n"

static char	*get_newstr(int fd, char *str)
{
	ssize_t	read_count;
	char	buf[BUFSIZE + 1];

	read_count = 1;
	while (read_count != 0)
	{
		read_count = read(fd, buf, BUFSIZE);
		if (read_count < 0)
			return (put_error("read", true), free(str), NULL);
		if (ft_memchr(buf, '\0', (size_t)read_count) != NULL)
			return (put_error(ERR_INVSTR, false), free(str), NULL);
		buf[read_count] = '\0';
		if (!valid_str(buf))
			return (put_error(ERR_INVSTR, false), free(str), NULL);
		str = append_buf(str, buf, (size_t)read_count);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}

char	*read_str(char *file)
{
	int		fd;
	char	*str;
	char	*new_str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (put_error(file, true), NULL);
	str = ft_calloc(1, sizeof(char));
	if (str == NULL)
		return (close(fd), put_error(ERR_ALLOC, false), NULL);
	new_str = get_newstr(fd, str);
	if (new_str == NULL)
		return (close(fd), NULL);
	str = new_str;
	close(fd);
	return (str);
}
