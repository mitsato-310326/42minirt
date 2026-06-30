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

t_hittable_list	*init_hittable(t_scene *scene)
{
	t_hittable_list	*hittable_list;

	(void)scene;
	hittable_list = create_obj();
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
	if (mlxs->cam == NULL)
	{
		; // 未実装
	}
	// scene_clear(scene);
	return mlxs;
}

// ------------ 一時的クソコード ------------ //

t_hittable_list	*create_obj(void)
{
	t_hittable_list	*world;
	t_hittable		*a_u;
	t_cylinder		*a;
	t_vec_three		point3a;
	t_material		*a_m;
	t_hittable		*j_u;
	t_cylinder		*j;
	t_vec_three		point3j;
	t_material		*j_m;
	t_hittable		*b_u;
	t_plane			*b;
	t_vec_three		point3b;
	t_vec_three		point3b2;
	t_material		*b_m;
	t_hittable		*c_u;
	t_sphere		*c;
	t_vec_three		point3c;
	t_material		*c_m;
	t_hittable		*d_u;
	t_sphere		*d;
	t_vec_three		point3d;
	t_material		*d_m;

	world = NULL;
	//
	a_u = malloc(sizeof(t_hittable));
	a = malloc(sizeof(t_cylinder));
	point3a = (struct s_vec_three){1.8, 0, -8.1};
	a->origin = point3a;
	a->axis = (struct s_vec_three){0.2, 0.89, 0.1};
	a->radius = 2.1; // ココ大きくしたら壊れた、わんちゃんカメラがオブジェクトにめり込んでいると動いてくれないかも
	a->height = 5.1;
	a->q = set_quaternion(a->axis);
	a_u->hit_fn = &hit_cylinder;
	a_m = malloc(sizeof(t_material));
	a_m->albedo = (struct s_vec_three){0.1, 0.1, 0.1};
	a_m->scatter_fn = NULL;
	a_u->material = a_m;
	a_u->object_unique_info = a;
	//
	j_u = malloc(sizeof(t_hittable));
	j = malloc(sizeof(t_cylinder));
	point3j = (struct s_vec_three){-2.2, -0.2, -8.1};
	j->origin = point3j;
	j->axis = (struct s_vec_three){0.3, 0.2, 0.4};
	j->radius = 2.1; // ココ大きくしたら壊れた、わんちゃんカメラがオブジェクトにめり込んでいると動いてくれないかも
	j->height = 5.1;
	j->q = set_quaternion(j->axis);
	j_u->hit_fn = &hit_cylinder;
	j_m = malloc(sizeof(t_material));
	j_m->albedo = (struct s_vec_three){0.1, 0.1, 0.1};
	j_m->scatter_fn = NULL;
	j_u->material = j_m;
	j_u->object_unique_info = j;
	b_u = malloc(sizeof(t_hittable));
	b = malloc(sizeof(t_plane));
	point3b = (struct s_vec_three){2.2, -2, -1};
	b->origin = point3b;
	point3b2 = (struct s_vec_three){0, 1, 0};
	b->normal = unit_vector(point3b2);
	b_u->hit_fn = &hit_plane;
	b_m = malloc(sizeof(t_material));
	b_m->albedo = (struct s_vec_three){0.7, 0.8, 0.6};
	b_m->scatter_fn = NULL;
	b_u->material = b_m;
	b_u->object_unique_info = b;
	c_u = malloc(sizeof(t_hittable));
	c = malloc(sizeof(t_sphere));
	point3c = (struct s_vec_three){4.0, 4.5, -4.5};
	c->origin = point3c;
	c->radius = 0.31;
	c_u->hit_fn = &hit_sphere;
	c_m = malloc(sizeof(t_material));
	c_m->albedo = (struct s_vec_three){0.8, 0.6, 0};
	c_m->scatter_fn = NULL;
	c_u->material = c_m;
	c_u->object_unique_info = c;
	d_u = malloc(sizeof(t_hittable));
	d = malloc(sizeof(t_sphere));
	point3d = (struct s_vec_three){-1, 0, -2};
	d->origin = point3d;
	d->radius = 0.5;
	d_u->hit_fn = &hit_sphere;
	d_m = malloc(sizeof(t_material));
	d_m->albedo = (struct s_vec_three){0.8, 0.8, 0.8};
	d_m->scatter_fn = NULL;
	d_u->material = d_m;
	d_u->object_unique_info = d;
	// ft_hlstadd_front(&world, ft_hlstnew(a_u));
	// ft_hlstadd_front(&world, ft_hlstnew(b_u));
	ft_hlstadd_front(&world, ft_hlstnew(j_u));
	// ft_hlstadd_front(&world, ft_hlstnew(c_u));
	ft_hlstadd_front(&world, ft_hlstnew(d_u));
	return (world);
}
