/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:32:16 by mitsato           #+#    #+#             */
/*   Updated: 2026/08/01 18:48:46 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# include "./ray_util.h"
# include "./vec_util.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>

// debug includes
# include "./camera.h"
# include "./ft_weekend.h"
# include "./hittable.h"
# include "./hittable_list.h"
# include "./parser.h"
# include "./parser_print.h"
# include "./parser_utils.h"
# include "./physics.h"
# include "./scene.h"
# include "./scene_utils.h"
# include "camera.h"
# include "light.h"

# define WIDTH 640
# define HEIGHT 360
# define RT ".rt"
# define RTLEN 3

/*											*/
typedef struct s_camera			t_camera;
typedef struct s_light_scene	t_light_scene;
typedef struct s_ambient		t_ambient;

typedef struct s_trange
{
	double						t_min;
	double						t_max;
}								t_trange;

typedef struct s_mlxs
{
	char						*mlx;
	char						*win;
	char						*img;
	char						*data;

	t_hittable_list				*hittable_list;
	t_camera					*cam;

	t_scene						*scene;
}								t_mlxs;

void							put_error(char *errstr, bool systemerr);
t_mlxs							*init(char *map);
int								destroy_minirt(t_mlxs *mlxs);
char							*read_str(char *file);
bool							valid_filename(char *file);
t_hittable						*create_cylinder_hittable(
									t_obj_content *content);
t_hittable						*create_sphere_hittable(
									t_obj_content *content);
t_hittable						*create_plane_hittable(
									t_obj_content *content);

/*					CALCULATE				*/

int								view_calc(t_mlxs *mlx);
t_vec_three						ray_color(t_ray *r, t_mlxs *mlxs);

/*					HOOK					*/

int								destroy_minirt(t_mlxs *mlxs);
int								stop_minirt(void *v_mlxs);
int								key_handler(int keycode, void *v_mlxs);

/*					PRINT					*/

bool							print(t_mlxs *mlxs);
void							my_pixel_put(char *data, int x, int y,
									t_vec_three *color);

/*					DEBUG					*/

# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

#endif
