/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:35:37 by keitotak          #+#    #+#             */
/*   Updated: 2026/07/26 14:38:30 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include "minirt.h"

char	**my_split(char const *s, char const *set);

// ft.c
int		ft_isspace(int c);
int		ft_issign(int c);
void	*ft_realloc(void *p, size_t size);
void	*ft_lstsearch(t_list *lst, int index);

// array.c
void	free_array(char **array, size_t size);
size_t	arrlen(char **array);
void	print_array(char **arr);

// cnv_arr_lst.c
char	**lst_to_arr(t_list *lst);
t_list	*arr_to_lst(char **arr);

#endif
