/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:45:58 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/27 01:50:06 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser_utils.h"

/*
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
*/

bool	empty_line(char *str)
{
	while (*str)
		if (!ft_isspace(*str++))
			return (false);
	return (true);
}

static void	remove_empty_line(t_list *lines)
{
	t_list	*prev;
	t_list	*next;

	while (lines)
	{
		if (empty_line(lines->content))
		{
			next = lines->next;
			free(lines->content);
			free(lines);
			lines = prev;
			lines->next = next;
		}
		prev = lines;
		lines = lines->next;
	}
}

t_list	*get_list(char *str, char const *set)
{
	char	**arr;
	t_list	*lines;

	arr = my_split(str, set);
	lines = arr_to_lst(arr);
	remove_empty_line(lines);
	return (lines);
}
/*
t_list	*get_lines(char *str)
{
	t_list	*lines;
	char	*line;

	lines = NULL;
	while (*str)
	{
		line = get_line(str);
		if (line == NULL)
		{
			ft_lstclear(&lines, free);
			return (NULL);
		}
		if (empty_line(line))
			free(line);
		else
			ft_lstadd_back(&lines, ft_lstnew(line));
		str = ft_strchr(str, '\n');
		if (str == NULL)
			break ;
		str++;
	}
	return (lines);
}
*/

// Should I use list instead of array from here because it's able to use pointer operation?
/*
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
*/
