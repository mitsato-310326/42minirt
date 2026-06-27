/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:32:16 by mitsato           #+#    #+#             */
/*   Updated: 2026/06/27 16:14:23 by keitotak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include "./ray_util.h"
#include "./vec_util.h"

//debug includes
#include "../../ft_mlx.h"
#include "../../os_setting.h"
#include "./hittable.h"
#include "./hittable_list.h"
#include "./sphere.h"
#include "./camera.h"
#include "./ft_weekend.h"
#include "./lambertian.h"
#include "./parser.h"
#include "./parser_utils.h"
#include "./scene.h"
#include "./scene_utils.h"

#define WIDTH 640
#define HEIGHT 360

/*											*/

typedef struct s_mlxs
{
	char *mlx;
	char *win;
	char *img;
	char *data;

	t_hittable_list *hittable_list;
	t_camera *cam;
}						t_mlxs;

void put_error(char *errstr, bool systemerr);
t_mlxs *init(char *map);
int destroy_minirt(t_mlxs *mlxs);
char	*read_str(char *file);

/*					CALCULATE				*/

int view_calc(t_mlxs *mlx);
t_vec_three ray_color(t_ray* r, t_hittable_list *world, int depth);

/*					HOOK					*/

int stop_minirt(void *v_mlxs);
int	key_handler(int keycode, void *v_mlxs);

/*					PRINT					*/

bool 	print(t_mlxs * mlxs);
void	my_pixel_put(char *data, int x, int y, double scale, t_vec_three *color);

/*					DEBUG					*/

#define BLUE   "\033[34m"
#define GREEN   "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

#define PERROR printf(RED "ERROR" RESET "\n");
#define PSUCCESS printf(GREEN "SUCCESS" RESET "\n");
/*#define // ENTRY(str) do { \
    static int i = 0; \
    if (i++ == 0) { \
        printf(BLUE "GET IN %s FUNCTION" RESET "\n", (str)); \
    } \
} while(0)
*/
/*											*/

#endif
