/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:59:28 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/28 17:39:43 by keitotak         ###   ########.fr       */
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
		return (free(str), NULL);
	free(str);
//	print_list(lines);
	elements = get_elements(lines);
	if (elements == NULL)
		return (ft_lstclear(&lines, free), NULL);
	ft_lstclear(&lines, free);
//	print_element(elements);
	scene = create_scene(elements);
	if (scene == NULL)
		return (ft_lstclear(&elements, delete_element), NULL);
	ft_lstclear(&elements, delete_element);
//	print_scene(scene);
	return (scene);
}
