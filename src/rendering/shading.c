#include "render.h"

bool     apply_checker(float u, float v)
{
    int   real_u;
    int   real_v;

    real_u = (int)(10 * u);
    real_v = (int)(5 * v);
    return (((real_u + real_v) % 2) == 0);
}

t_color     color_at_hit(t_shading* info, const t_light* l)
{
    float   lambertian;
    float   specular;
    t_vec4  half_way;
    t_color ret;

    ret = info->ret;
    lambertian = fmaxf(0.0f, 
            vector_dot_product(info->normal_at, info->light_dir));
    ret += info->obj_hit->color * l->effective * lambertian;
    half_way = vector_normalize
                    (info->light_dir + info->hitting_ray->direction);
    specular = fmaxf(0.0f, vector_dot_product(info->normal_at, half_way));
    specular = powf(specular, 100);
    ret += l->effective * specular * 200;
    return (ret);
}

void        get_shading_info(t_shading* shade_info, const t_ray* ray,
                                const t_world* world)
{
    shade_info->hitting_ray = ray;
    shade_info->hit_point = ray->direction * shade_info->t + ray->origin;
    shade_info->normal_at = shade_info->obj_hit->normal_get
                            (shade_info->obj_hit, shade_info);
    if(vector_dot_product(ray->direction, shade_info->normal_at) >= 0)
    {
        shade_info->normal_at = -shade_info->normal_at;
        shade_info->front_face = false;
    }
    shade_info->ret = shade_info->obj_hit->color * world->ambient;
}