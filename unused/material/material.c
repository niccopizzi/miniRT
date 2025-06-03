#include "material.h"
#include "render.h"

/*
 void   object_material_setup(t_object* obj, t_material  material)
{
    obj->material = material;
}
*/

/* void    objects_setup(t_object* ptr, size_t size)
{
    size_t  i;
    t_mat4  to_world;

    i = 0;
    while (i < size)
    {
        to_world = 
        (ptr + i)->to_obj = matrix4_inv
        i++;
    }
}  */

//objects_setup((t_object* )world->objects.data, world->objects.size);

/* 
t_ray      diffuse_bounce(const t_ray* r, const t_shading* info)
{
    t_vec4  bounced_dir;

    (void)r;
    bounced_dir = info->normal_at + random_unit_vector(-1, 1);
    if (vector_compare_eq(bounced_dir, (t_vec4){0, 0, 0, 0}))
        bounced_dir = info->normal_at;
    return (ray_create(info->hit_point, bounced_dir, DIFFUSE));
}

t_ray       mirror_bounce(const t_ray* r, const t_shading* info)
{
    return (ray_reflect(r, info->normal_at, info->hit_point));
}

float       reflectance(float cos, float refraction_index)
{
    float   r;

    r = (1 - refraction_index) / (1 + refraction_index);
    r *= r;
    return (r + (1 - r) * powf(1 - cos, 5));
}

t_ray       dieletric_bounce(const t_ray* r, const t_shading* info)
{
    float   ratio;
    float   ctheta;
    float   stheta;

    if (info->front_face)
        ratio = 1.0f / info->obj_hit->material.refraction_index;
    else 
        ratio = info->obj_hit->material.refraction_index;
    ctheta = fminf(vector_dot_product(-r->direction, info->normal_at), 1.0f);
    stheta = sqrtf(1.0f - ctheta * ctheta);
    if (ratio * stheta > 1.0 || reflectance(ctheta, ratio) > drand48())
        return (ray_reflect(r, info->normal_at, info->hit_point));
    return (ray_refract(r, info->normal_at, info->hit_point, ratio));
}

t_material  material_get_diffuse(void)
{
    t_material  diffuse;

    diffuse.bounce_ray = diffuse_bounce;
    return (diffuse);
} */