#include "light.h"
#include "mlx_utils.h"

void      light_move(t_ptrs *ptrs, int key)
{
    if (key == XK_Down)
        ptrs->world->light_src.pos[1] -= 1;
    else if (key == XK_Up)
        ptrs->world->light_src.pos[1] += 1;
    else if (key == XK_Left)
        ptrs->world->light_src.pos[0] -= 1;
    else if (key == XK_Right)
        ptrs->world->light_src.pos[0] += 1;

    /*call draw routine here*/
}

t_color   phong_lightning(const t_primitive *p, const t_light* light, 
                            const t_ray* eye_ray, const t_vec4* normal)
{
    t_color     result[4]; /* The different compontents of the phong lighting -> [EFFECTIVE, AMBIENT, DIFFUSE, SPECULAR]*/
    float       values[3]; /*[LIGHT - NORMAL DOT PRODUCT,
                            REFLECTED RAY - DIRECTION DOT PRODUCT, PHONG FACTOR]*/
    t_vec4      reflected_ray;
    t_vec4      light_vector;
    
    result[EFFECTIVE] = p->object->color * light->brightness;
    light_vector = vector_normalize(light->pos - eye_ray->origin);
    result[AMBIENT] = p->material.elem.ambient * result[EFFECTIVE];
    values[0] = vector_dot_product(light_vector, *normal);
    if (values[0] < 0)
        return (result[AMBIENT]);
    result[DIFFUSE] = result[EFFECTIVE] * p->material.elem.diffuse * values[0];
    reflected_ray = vector_reflect(-light_vector, *normal);
    values[1] = vector_dot_product(reflected_ray, eye_ray->direction);
    if (values[1] <= 0)
        return (result[AMBIENT] + result[DIFFUSE]);
    values[2] = powf(values[1], p->material.elem.shininess);
    result[SPECULAR] = vector_from_float(light->brightness *
                             p->material.elem.specular * values[2]);
    return (result[AMBIENT] + result[DIFFUSE] + result[SPECULAR]);
}
