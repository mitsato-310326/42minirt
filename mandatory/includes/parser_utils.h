/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:35:37 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/27 02:01:10 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

# include "minirt.h"

char	**my_split(char const *s, char const *set);
void	*ft_realloc(void *p, size_t size);
char	*ft_strndup(char *str, size_t n);

// array.c
void	free_array(char **array, size_t size);
size_t	arrlen(char **array);
void	print_array(char **arr);

// list.c
void	*ft_lstsearch(t_list *lst, int index);
void	print_list(t_list *list);

// cnv_arr_lst.c
char	**lst_to_arr(t_list *lst);
t_list	*arr_to_lst(char **arr);

#endif
