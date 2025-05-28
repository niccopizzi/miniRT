#include "render.h"

/* t_color   phong_lightning(const t_object *obj, const t_light* light,
                            const t_ray* eye_ray, t_vec4 normal)
{
    t_phong p;
    
    p.effective = obj->color * light->brightness;
    p.light_vector = -vector_normalize(light->pos - eye_ray->origin);
    p.ambient = obj->material[AMBIENT] * p.effective;
    p.ldn = vector_dot_product(p.light_vector, normal);
    if (p.ldn < 0)
        return (p.ambient);
    p.diffuse = p.effective * obj->material[DIFFUSE] * p.ldn;
    p.reflected_ray = vector_reflect(-p.light_vector, normal);
    p.rdd = vector_dot_product(p.reflected_ray, eye_ray->direction);
    if (p.rdd <= 0)
        return (p.ambient + p.diffuse);
    p.factor = powf(p.rdd, obj->material[SHININESS]);
    p.specular = vector_from_float(light->brightness *
                             obj->material[SPECULAR] * p.factor);
    return (p.ambient + p.diffuse + p.specular);
} */


void        get_shading_info(t_shading* shade_info, const t_ray* ray,
                                const t_light* l)
{
    shade_info->hit_point = ray_at(ray, shade_info->t);
    shade_info->normal_at = shade_info->obj_hit->normal_get
                            (shade_info->obj_hit, ray, shade_info->t);
    shade_info->light_dir = -(shade_info->hit_point - l->pos);
}