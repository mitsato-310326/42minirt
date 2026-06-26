/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 13:23:36 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/27 02:02:50 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"
# include "scene.h"

# define BUFSIZE 1024
# define SPACE " \t\n\v\f\r"

typedef enum s_id
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	ELSE
}	t_id;

typedef struct s_element
{
	t_list	*info;
	size_t	size;
	t_id	id;
}	t_element;

// parse.c
t_scene	*parse(char *file);

// read.c
char	*read_str(char *file);
int		ft_isspace(int c);
int		ft_issign(int c);

// lines.c
t_list	*get_list(char *str, char const *set);

// elements.c
t_list	*get_elements(t_list *lines);
void	delete_element(void *p);
void	print_element(t_list *element);

#endif
