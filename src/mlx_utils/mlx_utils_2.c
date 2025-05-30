#include "mlx_utils.h"

void    toggle_antialiasing(t_world* world)
{
    if (world->get_color == calculate_color)
        world->get_color = sample_pixel;
    else
        world->get_color = calculate_color;
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
    t_mat4              rotation;

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
    else if (key == XK_plus || key == Custom_plus)
        c->origin += c->forward * 1.5;
    else if (key == XK_minus || key == Custom_minus)
        c->origin -= c->forward * 1.5;
    c->to_world = camera_to_world(c);
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
    else if (key == XK_plus || key == Custom_plus)
        c->origin += c->forward * 1.5;
    else if (key == XK_minus || key == Custom_minus)
        c->origin -= c->forward * 1.5;
    c->to_world = camera_to_world(c);
}