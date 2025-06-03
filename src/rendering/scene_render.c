#include "render.h"

void    render_ui(t_ptrs* ptrs, t_world* world)
{
    char* num;

    mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, 
                                ptrs->img->img_ptr, 0, 0);
    if (world->get_color == calculate_color)
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 20, 40, 0xFFFFFF,
                    "ANTIALIASING OFF");
    else
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 20, 40, 0xFFFFFF,
                    "ANTIALIASING ON");
    if (world->light_moving >= 0)
    {
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 20 , 60, 0xFFFFFF,
                    "LIGHT MOVEMENT ACTIVE : ");
        num = ft_itoa(world->light_moving);
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 165, 61, 0xFFFFFF, num);
        free(num);
    }
}

t_color     calculate_color(int x, int y, const t_world* world, t_ray* r)
{
    t_point4    world_point;
    float       scale;

    scale = world->cam.scale;
    world_point = matrix4_mult_vec4(&world->cam.to_world, (t_vec4){
                            (2 * ((x + 0.5) / WIDTH) - 1) * scale * IMG_RATIO
                            ,(1 - 2 * ((y + 0.5) / HEIGHT)) * scale,
                            -1, 1});
    r->direction = vector_normalize(world_point - r->origin);
    return (ray_trace(r, world));
}


void    render_scene(t_ptrs* ptrs, t_world* world)
{
    int         x;
    int         y;
    t_ray       eye_ray;
    t_color     pixel_color;       

    y = 0;
    eye_ray.origin = world->cam.origin;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        { 
            pixel_color = world->get_color(x, y, world, &eye_ray);
            image_pixel_put(ptrs->img, x, y, to_rgb(pixel_color));
            x++;
        }
        y++;
    }
    render_ui(ptrs, world);
}
