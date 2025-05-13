#include "mlx_utils.h"

int window_close(t_ptrs *ptrs)
{
    mlx_destroy_image(ptrs->mlx_ptr, ptrs->img->img_ptr);
    mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
    mlx_destroy_display(ptrs->mlx_ptr), free(ptrs->mlx_ptr);
    free(ptrs->world->objects.data);
    exit(EXIT_SUCCESS);
}

int    set_cam_rotation(t_ptrs* ptrs, t_cam* c)
{
    c->rotate = !c->rotate; /*Flip the rotation mode, if it's false becomes true
                                if it's true becomes false*/
    render_scene(ptrs, ptrs->world);
    if (c->rotate == true)
    {
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 20, 20, 0xFFFFFF, "CAMERA ROTATION ACTIVE");
    }
    else
    {
        mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 20, 20, 0xFFFFFF, "CAMERA MOVEMENT ACTIVE");
    }
    return (1);
}

void     handle_cam_rotation(int key, t_cam* c)
{
    if (key == XK_Left)
        c->up = matrix4_mult_vec4(matrix4_rotate_y(5 * TO_RAD), c->up);
    else if (key == XK_Right)
        c->up = matrix4_mult_vec4(matrix4_rotate_y(-5 * TO_RAD), c->up);
    else if (key == XK_Up)
        c->up = matrix4_mult_vec4(matrix4_rotate_x(5 * TO_RAD), c->up);
    else if (key == XK_Down)
        c->up = matrix4_mult_vec4(matrix4_rotate_x(-5 * TO_RAD), c->up);
}

void     handle_cam_movement(int key, t_cam* c)
{
    if (key == XK_Left)
        c->origin[0] += 10;
    else if (key == XK_Right)
        c->origin[0] -= 10;
    else if (key == XK_Up)
        c->origin[1] += 10;
    else if (key == XK_Down)
        c->origin[1] -= 10;
    else if (key == XK_plus || key == Custom_plus)
        c->origin[2] -= 10;
    else if (key == XK_minus || key == Custom_minus)
        c->origin[2] += 10;
}

int    keys_hook(int key, t_ptrs* ptrs)
{
    if (key == XK_Escape)
        return (window_close(ptrs));
    if (key == XK_r)
        return (set_cam_rotation(ptrs, &ptrs->world->cam));
    if (ptrs->world->cam.rotate)
        handle_cam_rotation(key, &ptrs->world->cam);
    else
        handle_cam_movement(key, &ptrs->world->cam);
    render_scene(ptrs, ptrs->world);
    return (1);
}

void    hooks_set_up(t_ptrs *ptrs)
{
    mlx_hook(ptrs->win_ptr, 17, 0, window_close, ptrs);
    mlx_key_hook(ptrs->win_ptr, keys_hook, ptrs);
}
