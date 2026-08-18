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

#define ERR_INVSTR "invalid strings in the scene file.\n"

static char	*get_newstr(int fd, char *str)
{
	ssize_t	read_count;
	char	buf[BUFSIZE + 1];
	char	*new_str;

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
		new_str = ft_realloc(str, ft_strlen(str) + (size_t)read_count + 1);
		if (new_str == NULL)
			return (put_error("malloc", true), free(str), NULL);
		str = new_str;
		ft_strlcat(str, buf, ft_strlen(str) + (size_t)read_count + 1);
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
		return (close(fd), put_error("malloc", true), NULL);
	new_str = get_newstr(fd, str);
	if (new_str == NULL)
		return (close(fd), NULL);
	str = new_str;
	close(fd);
	return (str);
}
