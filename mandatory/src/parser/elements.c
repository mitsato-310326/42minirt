/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:45:58 by keitotak          #+#    #+#             */
/*   Updated: 2026/07/30 16:07:17 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

void	del_elm(void *p)
{
	t_element	*elm;

	elm = (t_element *)p;
	ft_lstclear(&elm->info, free);
	free(elm);
}

t_id	get_elmid(char *id_str)
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

#define ERR_INVID "invalid identifier is described in the scene file.\n"

static t_element	*create_element(char *str)
{
	t_element	*elm;

	elm = (t_element *)malloc(sizeof(t_element));
	if (elm == NULL)
		return (put_error("malloc", 1), NULL);
	elm->info = get_list(str, SPACE);
	if (elm->info == NULL)
	{
		free(elm);
		return (NULL);
	}
	elm->size = ft_lstsize(elm->info);
	elm->id = get_elmid(ft_lstsearch(elm->info, 0));
	if (elm->id == ELSE)
	{
		ft_lstclear(&elm->info, free);
		free(elm);
		return (put_error(ERR_INVID, 0), NULL);
	}
	return (elm);
}

static bool	check_doubled_id(t_list *lst)
{
	int			amb_cnt;
	int			cmr_cnt;
	int			lgt_cnt;
	t_element	*elm;

	amb_cnt = 0;
	cmr_cnt = 0;
	lgt_cnt = 0;
	while (lst)
	{
		elm = (t_element *)lst->content;
		if (get_elmid(elm->info->content) == AMBIENT)
			amb_cnt++;
		if (get_elmid(elm->info->content) == CAMERA)
			cmr_cnt++;
		if (get_elmid(elm->info->content) == LIGHT)
			lgt_cnt++;
		lst = lst->next;
	}
	if (amb_cnt > 1 || cmr_cnt > 1 || lgt_cnt > 1)
		return (true);
	return (false);
}

#define ERR_DBLID "unique id is doubled in the scene file.\n"

t_list	*get_elements(t_list *lines)
{
	t_list		*elm_lst;
	t_list		*node;
	t_element	*elm;

	elm_lst = NULL;
	while (lines)
	{
		elm = create_element(lines->content);
		if (elm == NULL)
			return (ft_lstclear(&elm_lst, del_elm), NULL);
		node = ft_lstnew(elm);
		if (node == NULL)
		{
			del_elm(elm);
			ft_lstclear(&elm_lst, del_elm);
			return (put_error("malloc", true), NULL);
		}
		ft_lstadd_back(&elm_lst, node);
		lines = lines->next;
	}
	if (check_doubled_id(elm_lst))
		return (ft_lstclear(&elm_lst, del_elm), put_error(ERR_DBLID, 0), NULL);
	return (elm_lst);
}
