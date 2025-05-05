#include "objects.h"

void    hit_set_face_normal(t_ray *ray, t_hit *hit, t_vec4 *normal)
{
    if (vector_dot_product(ray->direction, normal) < 0)
        hit->front_face = true;
    else
        hit->front_face = false;
    if (hit->front_face)
        hit->normal = *normal;
    else
        hit->normal = -(*normal);
}