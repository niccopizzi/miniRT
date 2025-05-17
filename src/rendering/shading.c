#include "render.h"

t_color   phong_lightning(t_object *obj, const t_light* light,
                             t_ray* eye_ray, t_vec4 normal)
{
    t_color     result[4]; /* The different compontents of the phong lighting -> [EFFECTIVE, AMBIENT, DIFFUSE, SPECULAR]*/
    float       values[3]; /*[LIGHT - NORMAL DOT PRODUCT,
                            REFLECTED RAY - DIRECTION DOT PRODUCT, PHONG FACTOR]*/
    t_vec4      reflected_ray;
    t_vec4      light_vector;
    
    result[EFFECTIVE] = obj->color * light->brightness;
    light_vector = vector_normalize(light->pos - eye_ray->origin);
    result[AMBIENT] = obj->material[AMBIENT] * result[EFFECTIVE];
    values[0] = vector_dot_product(light_vector, normal);
    if (values[0] < 0)
        return (result[AMBIENT]);
    result[DIFFUSE] = result[EFFECTIVE] * obj->material[DIFFUSE] * values[0];
    reflected_ray = vector_reflect(-light_vector, normal);
    values[1] = vector_dot_product(reflected_ray, eye_ray->direction);
    if (values[1] <= 0)
        return (result[AMBIENT] + result[DIFFUSE]);
    values[2] = powf(values[1], obj->material[SHININESS]);
    result[SPECULAR] = vector_from_float(light->brightness *
                             obj->material[SPECULAR] * values[2]);
    return (result[AMBIENT] + result[DIFFUSE] + result[SPECULAR]);
}
