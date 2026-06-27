/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_calc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:26:10 by mitsato           #+#    #+#             */
/*   Updated: 2026/05/04 15:37:14 by mitsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int view_calc(t_mlxs *mlxs)
{
    char *data = mlxs->data;
    t_camera *cam = mlxs->cam;
    double aspect_ratio = (double)WIDTH / HEIGHT;
    int image_width = WIDTH;
    int image_height = (int)(image_width / aspect_ratio);
    int samples_per_pixel = 8;
    double scale = 1.0 / samples_per_pixel;

    t_hittable_list *world = mlxs->hittable_list;
    t_light_list *light = mlxs->light_list;

    for (int j = image_height-1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; ++i)
        {
            t_vec_three pixel_color = (struct s_vec_three){0, 0, 0};
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + random_double()) / (image_width-1);
                double v = (j + random_double()) / (image_height-1);
                t_ray r = get_ray(u, v, *cam);
                pixel_color = vec_three_add(pixel_color, ray_color(&r, world, light, 15));
            }
            my_pixel_put(data, i, j, scale, &pixel_color);
        }
    }
    return 1;
}
