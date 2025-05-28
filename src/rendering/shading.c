#include "render.h"

t_color     color_at_hit(t_shading* info, const t_light* l, const t_world* w)
{
    float   lambertian;
    float   specular;
    t_vec4  half_way;
    t_color ret;

    ret = w->ambient * info->obj_hit->color;
    lambertian = fmaxf(0.0f, 
            vector_dot_product(info->normal_at, info->light_dir));
    ret += info->obj_hit->color * l->effective * lambertian 
            * info->obj_hit->material[DIFFUSE];
    half_way = vector_normalize
                    (info->light_dir - info->hitting_ray->direction);
    specular = fmaxf(0.0f, vector_dot_product(info->normal_at, half_way));
    specular = powf(specular, info->obj_hit->material[SHININESS]);
    ret += vector_from_float(info->obj_hit->material[SPECULAR]) *
                    l->effective * specular;
    return (ret);
}

void        get_shading_info(t_shading* shade_info, const t_ray* ray,
                                const t_light* l)
{
    shade_info->hitting_ray = ray;
    shade_info->hit_point = ray_at(ray, shade_info->t);
    shade_info->normal_at = shade_info->obj_hit->normal_get
                            (shade_info->obj_hit, ray, shade_info->t);
    shade_info->light_dir = -(shade_info->hit_point - l->pos); //get light ray direction
    shade_info->distance = vector_len(shade_info->light_dir); //get the distance from the point hit to the light 
    shade_info->light_dir /= shade_info->distance; //normalize the direction for correct shading

}