/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:45:58 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 00:38:44 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (arr == NULL)
		return (NULL);
	lines = arr_to_lst(arr);
	remove_empty_line(lines);
	return (lines);
}
