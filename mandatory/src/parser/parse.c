/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:59:28 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 11:39:02 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*parse(char *file)
{
	char	*str;
	t_list	*lines;
	t_list	*elements;
	t_scene	*scene;

	str = read_str(file);
	if (str == NULL)
		return (NULL);
	lines = get_list(str, NL);
	if (lines == NULL)
		return (free(str), NULL);
	free(str);
	elements = get_elements(lines);
	if (elements == NULL)
		return (ft_lstclear(&lines, free), NULL);
	ft_lstclear(&lines, free);
	scene = create_scene(elements);
	if (scene == NULL)
		return (ft_lstclear(&elements, delete_element), NULL);
	ft_lstclear(&elements, delete_element);
	return (scene);
}

/*
	print_str(str);
	print_list(lines);
	print_element(elements);
	print_scene(scene);
*/
