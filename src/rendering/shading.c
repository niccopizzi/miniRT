#include "render.h"

t_color     color_at_hit(t_shading* info, const t_light* l)
{
    float   lambertian;
    float   specular;
    t_vec4  half_way;
    t_color ret;

    ret = info->ambient;
    lambertian = fmaxf(0.0f, 
            vector_dot_product(info->normal_at, info->light_dir));
    ret += info->obj_hit->color * l->effective * lambertian 
            * info->obj_hit->material[DIFFUSE];
    half_way = vector_normalize
                    (info->light_dir + info->hitting_ray->direction);
    specular = fmaxf(0.0f, vector_dot_product(info->normal_at, half_way));
    specular = powf(specular, info->obj_hit->material[SHININESS]);
    ret += l->effective * specular * info->obj_hit->material[SPECULAR];
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
    shade_info->light_dir = (world->lights.pos - shade_info->hit_point);
    shade_info->distance = vector_len(shade_info->light_dir); 
    shade_info->light_dir *= (1 / shade_info->distance);
    shade_info->ambient = world->ambient * shade_info->obj_hit->color *
                                shade_info->obj_hit->material[AMBIENT];
}
