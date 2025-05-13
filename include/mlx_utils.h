/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:12:26 by npizzi            #+#    #+#             */
/*   Updated: 2025/05/13 19:16:10 by npizzi           ###   ########.fr       */
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

#define IMG_RATIO 1
#define WIDTH 1900
#define HEIGHT 1080

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
}   t_ptrs;

int     window_close(t_ptrs *ptrs);
void    connection_init(t_ptrs* ptrs, t_image* img, t_world* world);
void    image_pixel_put(t_image *image, int x, int y, int color);
int     hooks_key(int key, t_ptrs *ptrs);
void    hooks_set_up(t_ptrs *ptrs);
int     convert_to_rgb(t_color color);


//Forward declaration
void    render_scene(t_ptrs* ptrs, t_world* world);
/* 
void    display_light_palette(t_ptrs ptrs, t_image img);
void    draw_vertical_line(t_ptrs *ptrs, int x, int y, int max_y, int color);
void    draw_horizontal_line(t_ptrs *ptrs, int x, int y, int max_x, int color);
void    draw_plus_button(t_ptrs *ptrs, int x, int y, int color); */

#endif // MLX_UTILS_H