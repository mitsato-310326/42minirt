/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:18:49 by mitsato           #+#    #+#             */
/*   Updated: 2026/07/31 22:05:05 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

/* avoid casting macros; use typed local pointers instead */

int				stop_minirt(void *v_mlxs);
int				key_handler(int keycode, void *v_mlxs);

void	put_error(char *errstr, bool systemerr)
{
	if (systemerr)
		perror(NULL);
	else
		ft_putstr_fd(errstr, 2);
}

#define INIT_MLX_ERR "error"
#define TITLE "error"

bool	setup_mlx(t_mlxs *mlxs)
{
	int	bpp;
	int	size_line;
	int	endian;

	mlxs->mlx = mlx_init();
	if (mlxs->mlx == NULL)
		return (false);
	mlxs->win = mlx_new_window(mlxs->mlx, WIDTH, HEIGHT, TITLE);
	if (mlxs->win == NULL)
		return (false);
	mlxs->img = mlx_new_image(mlxs->mlx, WIDTH, HEIGHT);
	if (mlxs->img == NULL)
		return (false);
	mlxs->data = mlx_get_data_addr(mlxs->img, &bpp, &size_line, &endian);
	if (mlxs->data == NULL)
		return (false);
	mlx_hook(mlxs->win, 17, 0, stop_minirt, mlxs);
	mlx_key_hook(mlxs->win, key_handler, mlxs);
	return (true);
}

t_camera	*init_camera(t_camera_scene *camera)
{
	t_camera	*new;
	double		viewport_height;
	double		viewport_width;
	t_vec_three	tw;
	t_vec_three	unit_cross;

	viewport_width = 2.0 * tan(camera->fov * M_PI / 360);
	viewport_height = (double)HEIGHT / WIDTH * viewport_width;
	new = malloc(sizeof(t_camera));
	if (!new)
		return (NULL);
	tw = unit_vector(camera->vec);
	unit_cross = unit_vector(cross((t_vec_three){0, 1, 0}, tw));
	new->origin = (struct s_vec_three)camera->crd;
	new->horizontal = vec_three_mult(unit_cross, viewport_width);
	new->vertical = vec_three_mult(cross(tw, unit_vector(cross((t_vec_three){0,
						1, 0}, tw))), viewport_height);
	new->lower_left_corner = vec_three_add(vec_three_add(\
			vec_three_neg(new->origin,
					vec_three_mult(new->horizontal, 0.5)),
				vec_three_neg((t_vec_three){0, 0, 0},
					vec_three_mult(new->vertical, 0.5))), tw);
	return (new);
}

t_hittable_list	*create_obj(void);

t_hittable_list	*connect_hittable(t_list *scene_obj)
{
	t_hittable_list	*world;
	t_hittable		*tmp;
	t_obj_content	*content;

	world = NULL;
	while (scene_obj)
	{
		content = (t_obj_content *)scene_obj->content;
		tmp = NULL;
		if (content->id == CYLINDER)
			tmp = create_cylinder_hittable(content);
		else if (content->id == SPHERE)
			tmp = create_sphere_hittable(content);
		else if (content->id == PLANE)
			tmp = create_plane_hittable(content);
		if (tmp != NULL)
			ft_hlstadd_front(&world, ft_hlstnew(tmp));
		scene_obj = scene_obj->next;
	}
	return (world);
}

t_mlxs	*init(char *file)
{
	t_mlxs	*mlxs;
	t_scene	*scene;

	if (!valid_filename(file))
		return (printf("invalid filename.\n"), NULL);
	scene = parse(file);
	if (scene == NULL)
		return (scene_clear(scene), NULL);
	mlxs = malloc(sizeof(t_mlxs));
	if (mlxs == NULL)
	{
		put_error(NULL, 1);
		return (NULL);
	}
	mlxs->scene = scene;
	if (setup_mlx(mlxs) == false)
	{
		put_error(INIT_MLX_ERR, 0);
		destroy_minirt(mlxs);
		return (NULL);
	}
	mlxs->cam = init_camera(scene->camera);
	mlxs->hittable_list = connect_hittable(scene->objs);
	return (mlxs);
}
