/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 20:54:48 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/27 16:11:46 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "minirt.h"

typedef struct s_light
{
	t_vec_three pos;
	t_vec_three color;
	double	power;
}			t_light;

typedef struct s_light_list
{
	struct s_light_list *next;
	struct s_light *content;
}			t_light_list;

t_light_list	*ft_llstnew(void *content);
void ft_llstadd_front(t_light_list **lst, t_light_list *newl);
void ft_llstclear(t_light_list **lst);

t_light_list *create_lights();

#endif
