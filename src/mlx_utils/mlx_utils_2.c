#include "mlx_utils.h"

void    rotate_around_up_axis(float theta, t_vec4 axis, t_cam* c)
{
    t_mat4 rotation;

    rotation = matrix4_rodrigues_rot(axis, theta);
    c->forward = vector_normalize(matrix4_mult_vec4(&rotation, c->forward));
    c->right = vector_normalize(matrix4_mult_vec4(&rotation, c->right));
}

void    rotate_around_right_axis(float theta, t_vec4 axis, t_cam* c)
{
    t_mat4              rotation;

    rotation = matrix4_rodrigues_rot(axis, theta);
    c->forward = vector_normalize(matrix4_mult_vec4(&rotation, c->forward));
    c->up = vector_normalize(matrix4_mult_vec4(&rotation, c->up));
}

void    handle_cam_zoom(int key, t_cam* c, t_ptrs* ptrs)
{
    if (key == XK_plus || key == KEY_PLUS)
        c->origin += c->forward * 2;
    else if (key == XK_minus || key == KEY_MINUS)
        c->origin -= c->forward * 2;
    c->to_world = camera_to_world(c);
    render_scene(ptrs, ptrs->world);
}

void    handle_cam_rotation(int key, t_cam* c, t_ptrs* ptrs)
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
    c->to_world = camera_to_world(c);
    render_scene(ptrs, ptrs->world);
}

void     handle_cam_movement(int key, t_cam* c, t_ptrs* ptrs)
{
    if (key == XK_a)
        c->origin -= c->right * 2.f;
    else if (key == XK_d)
        c->origin += c->right * 2.f;
    else if (key == XK_w)
        c->origin += (c->up * 2.f);
    else if (key == XK_s)
        c->origin -= (c->up * 2.f);
    c->to_world = camera_to_world(c);
    render_scene(ptrs, ptrs->world);
}