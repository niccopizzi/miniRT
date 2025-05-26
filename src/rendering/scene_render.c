#include "render.h"

void    render_ui(t_ptrs* ptrs, t_world* world)
{
    mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, 
                                ptrs->img->img_ptr, 0, 0);
    if (world->cam.rotate)
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 20, 20, 0xFFFFFF, 
                    "CAMERA ROTATION ACTIVE");
    else
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 20, 20, 0xFFFFFF, 
                    "CAMERA TRANSLATION ACTIVE");
    if (world->light_src.move)
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 40 , 40, 0xFFFFFF,
                    "LIGHT MOVEMENT ACTIVE");
}

void    move_ray_to_world(t_ray* eye_ray, t_cam* cam, float x, float y)
{
    t_point4    world_point;

    world_point = matrix4_mult_vec4(&cam->to_world, (t_vec4){x, y, -1, 1});
    eye_ray->direction = vector_normalize(world_point - eye_ray->origin);
}

void    render_scene(t_ptrs* ptrs, t_world* world)
{
    int                 x;
    int                 y;
    float               p[2];
    const float         scale = tan(world->cam.fov * 0.5 * TO_RAD);
    t_ray               eye_ray;

    y = 0;
    eye_ray.origin = world->cam.origin;
    while (y < HEIGHT)
    {
        x = 0;
        p[1] = (1 - 2 * ((y + 0.5) / HEIGHT)) * scale;
        while (x < WIDTH)
        { 
            p[0] = (2 * ((x + 0.5) / WIDTH) - 1) * scale * IMG_RATIO;
            move_ray_to_world(&eye_ray, &world->cam, p[0], p[1]);
            image_pixel_put(ptrs->img, x, y, 
                            to_rgb(ray_trace(&eye_ray, world, 0)));
            x++;
        }
        y++;
    }
    render_ui(ptrs, world);
}
