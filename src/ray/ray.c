#include "objects.h"

inline t_ray   ray_create(t_point4 origin, t_vec4 direction, t_rtype type)
{
    t_ray   ray;

    ray.type = type;
    ray.origin = origin;
    ray.direction = direction;

    return (ray);
}

inline  t_point4    ray_at(t_ray ray, float time)
{
    return (vector_at(ray.origin, ray.direction, time));
}

t_ray       ray_transform(const t_ray *ray, const t_mat4 tm)
{
    t_ray   ray_transform;

    ray_transform.type = ray->type;
    ray_transform.origin = matrix4_mult_vec4(tm, ray->origin);
    ray_transform.direction = matrix4_mult_vec4(tm, ray->direction);
    
    return (ray_transform);
}

t_ray       ray_reflect(const t_ray *ray, const t_vec4 *normal, const t_point4  *p)
{
    t_ray   reflected_ray;
    
    reflected_ray.type = REFLECTIVE;
    reflected_ray.origin = *p;
    reflected_ray.direction = vector_reflect(ray->direction, *normal);
    return (reflected_ray);
}

t_color     ray_trace(t_ray *ray, const t_world* world)
{
    t_object* obj_ptr;
    size_t    obj_size;
    size_t    i;
    t_color   ret_color;
    double    t;
    double    t_min;

    ret_color = world->a_light.color;
    obj_ptr = (t_object*)world->objects.data;
    obj_size = world->objects.size;
    i = 0;
    t_min = START_VAL;
    while (i < obj_size)
    {
        if ((obj_ptr[i].hit(&obj_ptr[i], ray, &t)) && (t < t_min))
        {
                ret_color = obj_ptr[i].color;
                t_min = t;
        }
        i++;
    }
    return (ret_color);
}
