#include "objects.h"

t_vec4  sphere_normal(t_object* obj, t_ray r, float time)
{
    return (vector_normalize(ray_at(r, time) - obj->center));
}

t_vec4  plane_normal(t_object* obj, t_ray r, float time)
{
    (void)r;
    (void)time;
    return (obj->normal);
}
/* 
t_vec4  cylinder_normal(t_object obj, t_ray r, float time)
{

} */