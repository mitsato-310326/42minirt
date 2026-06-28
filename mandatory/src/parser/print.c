/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 00:41:30 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/29 01:08:52 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_str(char *str)
{
	printf("\n%s\n\n", str);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

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

void	print_scene(t_scene *scene)
{
	print_amblight(scene->amblight);
	print_camera(scene->camera);
	print_light(scene->light);
	print_objs(scene->objs);
}
