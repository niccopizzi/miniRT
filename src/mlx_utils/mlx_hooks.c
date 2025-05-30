#include "mlx_utils.h"

int window_close(t_ptrs *ptrs)
{
    mlx_destroy_image(ptrs->mlx_ptr, ptrs->img->img_ptr);
    mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
    mlx_destroy_display(ptrs->mlx_ptr), free(ptrs->mlx_ptr);
    free(ptrs->world->objects.data);
    exit(EXIT_SUCCESS);
}

int    keys_hook(int key, t_ptrs* ptrs)
{
    if (key == XK_Escape)
        return (window_close(ptrs));
    if (key == XK_r)
        return (reload(ptrs));
    if (key == XK_c)
        ptrs->world->cam.rotate = !ptrs->world->cam.rotate;
    else if (key == XK_a)
        toggle_antialiasing(ptrs->world);
    else if (key == XK_l)
        ptrs->world->lights.move = !ptrs->world->lights.move;
    else if (ptrs->world->cam.rotate)
        handle_cam_rotation(key, &ptrs->world->cam);
    else
        handle_cam_movement(key, &ptrs->world->cam);
    render_scene(ptrs, ptrs->world);
    return (1);
}


int     mouse_hook(int button, int x, int y, t_ptrs* ptrs)
{
    t_vec4      dir;
    t_point4    p;
    float       t;
    
    if (button == 1 && ptrs->world->lights.move)
    {
        dir = vector_normalize((t_vec4){
            get_camera_x(x, ptrs->world->cam.scale),
            get_camera_y(y, ptrs->world->cam.scale), 
            ptrs->world->cam.forward[2], 0});
        dir = matrix4_mult_vec4(&ptrs->world->cam.to_world, dir);
        t = (ptrs->world->lights.pos[2] - ptrs->world->cam.origin[2]) / dir[2];
        p = ptrs->world->cam.origin + t * dir;
        ptrs->world->lights.pos[0] = p[0];
        ptrs->world->lights.pos[1] = p[1];
        render_scene(ptrs, ptrs->world);
    }
    return (1);
}

void    hooks_set_up(t_ptrs* ptrs)
{
    mlx_hook(ptrs->win_ptr, 17, 0, window_close, ptrs);
    mlx_key_hook(ptrs->win_ptr, keys_hook, ptrs);
    mlx_mouse_hook(ptrs->win_ptr, mouse_hook, ptrs);
}
