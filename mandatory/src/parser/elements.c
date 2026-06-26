/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:45:58 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/27 02:02:12 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
void	print_element(t_list *elm_lst)
{
	t_element	*elm;
	int i = 0;
	printf("\n");
	while (elm_lst)
	{
		printf("\nelement:%d\n", i++);
		elm = (t_element *)elm_lst->content;
		printf("size:\t%ld\n", elm->size);
		printf("ID:\t%s\n", (char *)elm->info->content);
		while (elm->info->next)
		{
			printf("info:\t%s\n", (char *)elm->info->next->content);
			elm->info = elm->info->next;
		}
		elm_lst = elm_lst->next;
	}
	printf("\n");
}
*/

/*void ft_lstclear(t_list **lst, void (*del)(void *))*/

void	delete_element(void *p)
{
	t_element	*elm;

	elm = (t_element *)p;
	ft_lstclear(&elm->info, free);
	free(elm);
}

static t_id	get_elmid(char *id_str)
{
	if (ft_strncmp(id_str, "A", 2) == 0)
		return (AMBIENT);
	if (ft_strncmp(id_str, "C", 2) == 0)
		return (CAMERA);
	if (ft_strncmp(id_str, "L", 2) == 0)
		return (LIGHT);
	if (ft_strncmp(id_str, "sp", 3) == 0)
		return (SPHERE);
	if (ft_strncmp(id_str, "pl", 3) == 0)
		return (PLANE);
	if (ft_strncmp(id_str, "cy", 3) == 0)
		return (CYLINDER);
	return (ELSE);
}

static t_element	*create_element(char *str)
{
	t_element	*elm;

	elm = (t_element *)malloc(sizeof(t_element));
	if (elm == NULL)
		return (NULL);
	elm->info = get_list(str, SPACE);
	if (elm->info == NULL)
	{
		free(elm);
		return (NULL);
	}
	elm->size = ft_lstsize(elm->info);
	elm->id = get_elmid(ft_lstsearch(elm->info, 1));
	if (elm->id == ELSE)
	{
		ft_lstclear(&elm->info, free);
		free(elm);
		return (NULL);
	}
	return (elm);
}

t_list	*get_elements(t_list *lines)
{
	t_list		*elm_lst;
	t_element	*elm;

	elm_lst = NULL;
	while (lines)
	{
		elm = create_element(lines->content);
		if (elm == NULL)
		{
			ft_lstclear(&elm_lst, delete_element);
			return (NULL);
		}
		ft_lstadd_back(&elm_lst, ft_lstnew(elm));
		lines = lines->next;
	}
	return (elm_lst);
}

/*
void	free_element(t_list **element, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_lstclear(&element[i], free);
		i++;
	}
	free(element);
}

t_list	**get_elements(t_list *lines)
{
	t_list	**elements;
	size_t	size;
	size_t	i;

	size = ft_lstsize(lines);
	elements = (t_list **)malloc(sizeof(t_list *) * (size + 1));
	if (elements == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		elements[i] = get_list(lines->content, SPACE);
		if (elements[i] == NULL)
		{
			free_element(elements, i);
			return (NULL);
		}
		lines = lines->next;
		i++;
	}
	elements[size] = NULL;
	return (elements);
}
*/
