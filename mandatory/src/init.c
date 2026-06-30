/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitotak <keitotak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:18:49 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/29 11:40:48 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

#define cyl_path ((t_cylinder_scene *)content->obj)
#define sph_path ((t_sphere_scene *)content->obj)
#define pln_path ((t_plane_scene *)content->obj)

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
	mlxs->mlx = mlx_init();
	if (mlxs->mlx == NULL)
		return (false);
	mlxs->win = mlx_new_window(mlxs->mlx, WIDTH, HEIGHT, TITLE);
	if (mlxs->win == NULL)
		return (false);
	mlxs->img = mlx_new_image(mlxs->mlx, WIDTH, HEIGHT);
	if (mlxs->img == NULL)
		return (false);
	mlxs->data = mlx_get_data_addr(mlxs->img, &(int){0}, &(int){0}, &(int){0});
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

	// (void)camera;
	/*
	focal_lengthに関して、
	*/

	viewport_width = 2.0 * tan(camera->fov * M_PI / 360);
	viewport_height = (double)HEIGHT / WIDTH * viewport_width;
	new = malloc(sizeof(t_camera));
	if (!new)
		return (NULL);
	t_vec_three w = unit_vector(camera->vec);      // 視線方向（normalize前提）
	t_vec_three world_up = (t_vec_three){0, 1, 0}; // 上方向（uとwが正規直交ならvも単位ベクトル）
	new->origin = (struct s_vec_three)camera->crd;
	new->horizontal = vec_three_mult(unit_vector(cross(world_up, w)), viewport_width);
	new->vertical = vec_three_mult(cross(w, unit_vector(cross(world_up, w))), viewport_height); // 要整理
	new->lower_left_corner = vec_three_neg(vec_three_neg(vec_three_neg(new->origin,
					vec_three_mult(new->horizontal, 0.5)),
				vec_three_mult(new->vertical, 0.5)), (struct s_vec_three){0, 0, 1});
	return (new);
}

t_hittable_list	*create_obj(void);

t_hittable_list	*init_hittable(t_scene *scene)//未使用
{
	t_hittable_list	*hittable_list = NULL;

	(void)scene;
	// hittable_list = create_obj();
	if (hittable_list == NULL)
		return (NULL);
	return (hittable_list);
}

#define RT ".rt"
#define RTLEN 3

bool	valid_filename(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	file += len - RTLEN;
	if (ft_strncmp(file, RT, RTLEN + 1) == 0)
		return (true);
	return (false);
}

t_hittable_list *connect_hittable(t_list *scene_obj)
{
	t_hittable_list	*world = NULL;
	t_hittable *tmp;
	t_obj_content *content;

	while(scene_obj)
	{
		content = (t_obj_content *)scene_obj->content;
		if (content->id == CYLINDER)
		{
			tmp = malloc(sizeof(t_hittable));//
			tmp->color = ((t_cylinder_scene *)content->obj)->color;
			tmp->hit_fn = &hit_cylinder;
			t_cylinder *cyl;
			cyl = malloc(sizeof(t_cylinder));
			cyl->origin = cyl_path->crd;
			cyl->axis = cyl_path->vec;
			cyl->radius = cyl_path->diameter / 2.0;
			cyl->height = cyl_path->height;
			cyl->q = set_quaternion(cyl->axis);
			tmp->object_unique_info = cyl;
		}
		else if (content->id == SPHERE)
		{
			tmp = malloc(sizeof(t_hittable));//
			t_sphere *sph;
			sph = malloc(sizeof(t_sphere));
			tmp->color = sph_path->color;
			tmp->hit_fn = &hit_sphere;
			sph->origin = sph_path->crd;
			sph->radius = sph_path->diameter / 2.0;
			tmp->object_unique_info = sph;
		}
		else if (content->id == PLANE)
		{
			t_plane *pln;
			tmp = malloc(sizeof(t_hittable));//
			pln = malloc(sizeof(t_plane));
			tmp->color = pln_path->color;
			tmp->hit_fn = &hit_plane;
			pln->normal = pln_path->vec;
			pln->origin = pln_path->crd;
			tmp->object_unique_info = pln;
		}
		else 
		{
			scene_obj = scene_obj->next;
			continue;
		}
		scene_obj = scene_obj->next;
		ft_hlstadd_front(&world, ft_hlstnew(tmp));
	}
	return(world);
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
		put_error(NULL, 1); // malloc失敗
		return (NULL);
	}
	mlxs->hittable_list = init_hittable(scene); //配列を作ってるからポインタは適切
	// sceneslight = create_lights();
	mlxs->scene = scene;
	if (mlxs->hittable_list == NULL)
	{
		; // 未実装
	}
	if (setup_mlx(mlxs) == false)
	{
		put_error(INIT_MLX_ERR, 0);
		destroy_minirt(mlxs);
		return (NULL);
	}
	mlxs->cam = init_camera(scene->camera);
	mlxs->hittable_list = connect_hittable(scene->objs);
	if (mlxs->cam == NULL)
	{
		; // 未実装
	}
	// scene_clear(scene);
	return mlxs;
}
