/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:12:26 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/03 00:44:39 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
#define MLX_UTILS_H

#include "../lib/minilibx-linux/mlx.h"
#include "world.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>

#define WIDTH 1980
#define HEIGHT 1020
#define IMG_RATIO (float)WIDTH / HEIGHT

#define Custom_plus 65451
#define Custom_minus 65453

typedef struct s_image
{
    int     endianess;
    int     size_line;
    int     bits_per_pixel;
    char    *img_address;
    void    *img_ptr;
    void    *base_img;
}   t_image;

typedef struct s_ptrs
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_image     *img;
    t_world     *world;
    char        *filename;
}   t_ptrs;

int     window_close(t_ptrs *ptrs);
void    connection_init(t_ptrs* ptrs, t_image* img, t_world* world);
void    image_pixel_put(t_image *image, int x, int y, int color);
int     keys_hook(int key, t_ptrs *ptrs);
void    hooks_set_up(t_ptrs *ptrs);
int     to_rgb(t_color color);
int     reload(t_ptrs* ptrs);

void    rotate_around_up_axis(float theta, t_vec4 axis, t_cam* c);
void    rotate_around_right_axis(float theta, t_vec4 axis, t_cam* c);
void    handle_cam_rotation(int key, t_cam* c);
void    handle_cam_movement(int key, t_cam* c);
void    toggle_antialiasing(t_world* world);

//Forward declarations
void    render_scene(t_ptrs* ptrs, t_world* world);
void    camera_setup(t_cam* c);
bool    is_valid_file(char *filename, t_world *world);


#endif // MLX_UTILS_H