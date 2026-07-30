/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 09:38:48 by keitotak          #+#    #+#             */
/*   Updated: 2026/07/30 15:43:22 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}

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

char	*read_str(char *file)
{
	int		fd;
	int		read_count;
	char	buf[BUFSIZE + 1];
	char	*str;

	fd = open(file, O_RDONLY);
	read_count = 1;
	str = ft_calloc(1, sizeof(char));
	while (read_count != 0)
	{
		read_count = read(fd, buf, BUFSIZE);
		if (read_count < 0)
			return (PERROR, put_error("read", 1), free(str), NULL);
		buf[read_count] = '\0';
		str = ft_realloc(str, ft_strlen(str) + read_count + 1);
		if (str == NULL)
			return (PERROR, put_error("malloc", 1), free(str), NULL);
		ft_strlcat(str, buf, ft_strlen(str) + read_count + 1);
	}
	if (!valid_str(str))
		return (PERROR, put_error(ERR_INVSTR, 0), free(str), NULL);
	return (str);
}
