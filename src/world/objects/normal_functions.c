#include "objects.h"

t_vec4  sphere_normal(const t_object* obj, const t_ray* r, float time)
{
    return (vector_normalize(ray_at(r, time) - obj->center));
}

t_vec4  plane_normal(const t_object* obj, const t_ray* r, float time)
{
    (void)time;
    (void)r;
    /* 
    if (vector_dot_product(r->direction, obj->normal) < 0)
        return (-obj->normal); */
    return (obj->normal);
}

t_vec4  cylinder_normal(const t_object* obj, const t_ray* r, float time)
{
    t_vec4  v;
    t_vec4  proj;

    v = ray_at(r, time) - obj->center;
    proj = vector_dot_product(v, obj->axis) * obj->axis;
    return (vector_normalize(v - proj));
}