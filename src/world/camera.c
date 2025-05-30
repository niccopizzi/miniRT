#include "world.h"
#include "miniRT.h"

t_mat4  camera_to_world(t_cam* cam)
{
    t_mat4  to_world;

    to_world = matrix4_identity();
    to_world.row[0] = cam->right;
    to_world.row[1] = cam->up;
    to_world.row[2] = -cam->forward;
    to_world.row[3] = cam->origin;
    
    return (matrix4_transpose(to_world));
}

inline float   get_camera_x(int x, float scale)
{
    return ((2 * ((x + 0.5) / WIDTH) - 1) * scale * IMG_RATIO);
}

inline float    get_camera_y(int y, float scale)
{
    return ((1 - 2 * ((y + 0.5) / HEIGHT)) * scale);
}

void    camera_setup(t_cam* c)
{
    t_vec4  tmp_up = (t_vec4){0, 1, 0, 0};
    
    if (fabsf(vector_dot_product(tmp_up, c->forward)) > 1.0f - EPSILON)
    {
        tmp_up = (t_vec4){0, 0, 1, 0};
    }
    c->right = vector_normalize(vector_cross_prod(c->forward, tmp_up));
    c->up = vector_normalize(vector_cross_prod(c->right, c->forward));
    c->scale = tan(c->fov * 0.5 * TO_RAD);
    c->to_world = camera_to_world(c);
}
