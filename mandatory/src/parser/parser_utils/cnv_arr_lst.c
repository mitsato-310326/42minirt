/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_arr_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:12:58 by keitotak          #+#    #+#             */
/*   Updated: 2026/08/01 19:01:54 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*arr_to_lst(char **arr)
{
	t_list	*lst;
	char	*content;

	lst = NULL;
	while (*arr)
	{
		content = ft_strdup(*arr);
		if (content == NULL)
		{
			ft_lstclear(&lst, free);
			return (put_error("malloc", 1), NULL);
		}
		ft_lstadd_back(&lst, ft_lstnew(content));
		arr++;
	}
	return (lst);
}

char	**lst_to_arr(t_list *lst)
{
	char	**arr;
	size_t	size;
	size_t	i;

	size = ft_lstsize(lst);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = ft_strdup(lst->content);
		if (arr[i] == NULL)
		{
			free_array(arr, i);
			return (NULL);
		}
		i++;
		lst = lst->next;
	}
	return (arr);
}
