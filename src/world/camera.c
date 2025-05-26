#include "world.h"

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

void    camera_setup(t_cam* c)
{
    c->up = (t_vec4){0, 1, 0, 0};
    if (fabsf(vector_dot_product(c->up, c->forward)) == 1.f)
    {
        c->up = (t_vec4){0, 0, 1, 0};
    }
    c->right = vector_normalize(vector_cross_prod(c->forward, c->up));
    c->up = vector_normalize(vector_cross_prod(c->right, c->forward));
    c->distance = 1 / tan((c->fov * 0.5 * TO_RAD));
    c->to_world = camera_to_world(c);
}
