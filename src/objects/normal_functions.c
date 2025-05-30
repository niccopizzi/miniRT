#include "objects.h"
#include "render.h"

t_vec4  sphere_normal(const t_object* obj, t_shading* info)
{
    return ((info->hit_point - obj->center) / obj->radius);
}

t_vec4  plane_normal(const t_object* obj, t_shading* info)
{
    (void)info;
    return (obj->normal);
}

t_vec4  cylinder_normal(const t_object* obj, t_shading* info)
{
    t_vec4  v;
    t_vec4  proj;

    v = info->hit_point - obj->center;
    proj = vector_dot_product(v, obj->axis) * obj->axis;
    return ((v - proj) / obj->radius);
}

t_vec4  cone_normal(const t_object* obj, t_shading* info)
{
    t_vec4  v;
    t_vec4  proj;

    v = info->hit_point - obj->center;
    proj = vector_dot_product(v, obj->axis) * obj->axis;
    return ((v - proj) / obj->radius);
}