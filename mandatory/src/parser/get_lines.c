/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:45:58 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/25 16:06:09 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static size_t	count_c(char *str, int c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

static char	*get_line(char *str)
{
	size_t	size;
	char	*line;

	if (ft_strchr(str, '\n'))
		size = ft_strchr(str, '\n') - str;
	else
		size = ft_strlen(str);
	line = ft_strndup(str, size);
	return (line);
}

char	**get_lines(char *str)
{
	char	**lines;
	size_t	line_nb;
	size_t	i;

	line_nb = count_c(str, '\n') + 1;
	lines = (char **)malloc(sizeof(char *) * (line_nb + 1));
	if (lines == NULL)
		return (NULL);
	i = 0;
	while (i < line_nb)
	{
		lines[i] = get_line(str);
		if (lines[i] == NULL)
		{
			free_array(lines, i);
			return (NULL);
		}
		str = ft_strchr(str, '\n') + 1;
		i++;
	}
	lines[line_nb] = NULL;
	return (lines);
}
