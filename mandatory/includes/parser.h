/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:23:36 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/25 15:47:21 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"

# define BUFSIZE 1024

// read.c
char	*read_str(char *file);

// get_lines.c
char	**get_lines(char *str);

// parse_util.c
void	*ft_realloc(void *p, size_t size);
char	*ft_strndup(char *str, size_t size);
int		ft_isspace(int c);
int		ft_issign(int c);
void	free_array(char **array, size_t size);

// array.c
size_t	arrlen(char **array);
void	print_array(char **arr);

#endif
