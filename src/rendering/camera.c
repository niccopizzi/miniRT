#include "render.h"

void    camera_setup(t_cam* c)
{
    c->forward = (t_vec4){0, 0, 1, 0};
    if (fabsf(vector_dot_product(c->up, c->forward)) == 1.f)
    {
        c->forward = (t_vec4){0, 1, 0, 0};
    }
    c->right = vector_normalize(vector_cross_prod(c->forward, c->up));
    c->up = vector_normalize(vector_cross_prod(c->forward, c->right));
    c->distance = HEIGHT / (2 * tan((c->fov * 0.5 * TO_RAD)));
}

t_vec4  camera_to_world(float x, float y, t_cam* cam)
{
    t_vec4  res;

    res = x * cam->right + y * cam->up - cam->distance * cam->forward;
    return(vector_normalize(res));
}