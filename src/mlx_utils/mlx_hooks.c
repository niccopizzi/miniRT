#include "mlx_utils.h"

int window_close(t_ptrs *ptrs)
{
    mlx_destroy_image(ptrs->mlx_ptr, ptrs->img->img_ptr);
    mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
    mlx_destroy_display(ptrs->mlx_ptr), free(ptrs->mlx_ptr);
    free(ptrs->world->objects.data);
    exit(EXIT_SUCCESS);
}

void    rotate_around_up_axis(float theta, t_vec4 axis, t_cam* c)
{
    t_mat4 rotation;

    rotation = matrix4_rodrigues_rot(axis, theta);
    c->forward = vector_normalize(matrix4_mult_vec4(&rotation, c->forward));
    c->right = vector_normalize(matrix4_mult_vec4(&rotation, c->right));
}

void    rotate_around_right_axis(float theta, t_vec4 axis, t_cam* c)
{
    t_mat4  rotation;

    rotation = matrix4_rodrigues_rot(axis, theta);
    c->forward = vector_normalize(matrix4_mult_vec4(&rotation, c->forward));
    c->up = vector_normalize(matrix4_mult_vec4(&rotation, c->up));
}

void    handle_cam_rotation(int key, t_cam* c)
{
    const float theta = 5.0f * TO_RAD;

    if (key == XK_Left)
        rotate_around_up_axis(theta, c->up, c);
    else if (key == XK_Right)
        rotate_around_up_axis(-theta, c->up, c);
    else if (key == XK_Up)
        rotate_around_right_axis(theta, c->right, c);
    else if (key == XK_Down)
        rotate_around_right_axis(-theta, c->right, c);
}

void     handle_cam_movement(int key, t_cam* c)
{
    if (key == XK_Left)
        c->origin -= c->right * 2.f;
    else if (key == XK_Right)
        c->origin += c->right * 2.f;
    else if (key == XK_Up)
        c->origin -= (c->up * 2.f);
    else if (key == XK_Down)
        c->origin += (c->up * 2.f);
}

int    keys_hook(int key, t_ptrs* ptrs)
{
    if (key == XK_Escape)
        return (window_close(ptrs));
    if (key == XK_r)
        return (reload(ptrs));
    if (key == XK_c)
        ptrs->world->cam.rotate = !ptrs->world->cam.rotate;
    else if (key == XK_l)
        ptrs->world->light_src.move = !ptrs->world->light_src.move;
    else if (key == XK_plus || key == Custom_plus)
        ptrs->world->cam.origin += ptrs->world->cam.forward * 1.5;
    else if (key == XK_minus || key == Custom_minus)
        ptrs->world->cam.origin -= ptrs->world->cam.forward * 1.5;
    else if (ptrs->world->cam.rotate)
        handle_cam_rotation(key, &ptrs->world->cam);
    else
        handle_cam_movement(key, &ptrs->world->cam);
    camera_setup(&ptrs->world->cam);
    render_scene(ptrs, ptrs->world);
    return (1);
}


int     mouse_hook(int button, int x, int y, t_ptrs* ptrs)
{
    if (button == 1 && ptrs->world->light_src.move)
    {
        t_mat4  inverse = matrix4_transpose(ptrs->world->cam.to_world);
        float ndc_x = (2.0f * (x + 0.5f) / WIDTH  - 1.0f) * IMG_RATIO;
        float ndc_y = (1.0f - 2.0f * (y + 0.5f) / HEIGHT);
        float scale = tan(ptrs->world->cam.fov * 0.5f * TO_RAD);
        float cam_x = ndc_x * scale;
        float cam_y = ndc_y * scale;
        t_vec4 ray_dir_cam = vector_normalize((t_vec4){cam_x, cam_y, ptrs->world->cam.forward[2], 0});
        t_vec4 ray_dir_world = matrix4_mult_vec4(&inverse, ray_dir_cam);
        float t = (ptrs->world->light_src.pos[2] - ptrs->world->cam.origin[2]) / ray_dir_world[2];
        t_point4    P = ptrs->world->cam.origin + t * ray_dir_world;
        ptrs->world->light_src.pos[0] = P[0];
        ptrs->world->light_src.pos[1] = P[1];
        render_scene(ptrs, ptrs->world);
    }
}


void    hooks_set_up(t_ptrs* ptrs)
{
    mlx_hook(ptrs->win_ptr, 17, 0, window_close, ptrs);
    mlx_key_hook(ptrs->win_ptr, keys_hook, ptrs);
    mlx_mouse_hook(ptrs->win_ptr, mouse_hook, ptrs);
}
