/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:59:28 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/27 02:06:54 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*parse(char *file)
{
	char	*str;
	t_list	*lines;
	t_list	*elements;
	t_scene		*scene;

	str = read_str(file);
	if (str == NULL)
		return (NULL);
//	printf("%s\n", str);
	lines = get_list(str, "\n");
	if (lines == NULL)
	{
		free(str);
		return (NULL);
	}
	free(str);
//	print_list(lines);
	elements = get_elements(lines);
	if (elements == NULL)
	{
		ft_lstclear(&lines, free);
		return (NULL);
	}
	ft_lstclear(&lines, free);
//	print_element(elements);
	scene = create_scene(elements);
	if (scene == NULL)
	{
		ft_lstcler(&elements, delete_element);
		return (NULL);
	}
	ft_lstcler(&elements, delete_element);
	return (scene);
}

