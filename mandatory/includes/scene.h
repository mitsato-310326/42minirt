/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 10:26:38 by keitotak          #+#    #+#             */
/*   Updated: 2026/06/23 13:13:46 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vec_three t_coord;

typedef struct s_amblight_scene
{
	double	ratio;
	t_color	color;
}	t_amblight_scene;

typedef struct s_camera_scene
{
	t_coord		point;
	t_vec_three	vec;
	int			fov;
}	t_camera_scene;

typedef struct s_light_scene
{
	t_coord		point;
	double		ratio;
	t_color		color;
}	t_light_scene;

typedef struct s_sphere_scene
{
	t_coord	center;
	double	diameter;
	t_color	color;
}	t_sphere_scene;

typedef struct s_plane_scene
{
	t_coord		point;
	t_vec_three	vec;
	t_color		color;
}	t_plane_scene;

typedef struct s_cylinder_scene
{
	t_coord	center;
	t_vec_three	vec;
	double	diameter;
	double	height;
	t_color	color;
}	t_cylinder_scene;

typedef struct s_obj_node
{
	int					id;
	void				*content;
	struct s_scene_node	*next;
}	t_obj_node;

typedef struct s_scene
{
	t_amblight_scene	*amblight;
	t_camera_scene		*camera;
	t_light_scnene		*light;
	t_obj_node			*objs;
}	t_scene;

#endif
