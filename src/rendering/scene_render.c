#include "render.h"

#define PIXEL_SIZE 1

void    render_ui(t_ptrs* ptrs, t_world* world)
{
    if (world->cam.rotate)
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 20, 20, 0xFFFFFF, 
                    "CAMERA ROTATION ACTIVE");
    else
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 20, 20, 0xFFFFFF, 
                    "CAMERA TRANSLATION ACTIVE");
}

void    render_scene(t_ptrs* ptrs, t_world* world)
{
    int         x;
    int         y;
    float       p[2];
    t_ray       eye_ray;

    y = 0;
    eye_ray.origin = world->cam.origin;
    while (y < HEIGHT)
    {
        x = 0;
        p[1] = PIXEL_SIZE * (y - ((HEIGHT - 1) * 0.5));
        while (x < WIDTH)
        { 
            p[0] = PIXEL_SIZE * (x - ((WIDTH - 1) * 0.5));
            eye_ray.direction = camera_to_world(p[0], p[1], &world->cam);
            image_pixel_put(ptrs->img, x, y, to_rgb(ray_trace(&eye_ray, world)));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, 
                                ptrs->img->img_ptr, 0, 0);
    render_ui(ptrs, world);
}
