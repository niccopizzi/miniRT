#include "objects.h"

inline t_object    sphere_new(t_point4 center, float radius)
{
    t_object    sphere;

    sphere.center = center;
    sphere.type = SP;
    sphere.radius = radius;
    sphere.transform = matrix4_identity();
    sphere.color = (t_vec4){1, 0, 0, 0};
    return (sphere);
}

inline void     sphere_set_transform(t_object *sphere, t_mat4 tm)
{
    sphere->transform = tm;
}

t_vec4  sphere_normal_at(t_object *sphere, t_point4 *p)
{
    t_vec4      normal;
    t_mat4      tm;
    t_point4    p_object;

    p_object = matrix4_mult_vec4(sphere->transform, *p);
    normal = p_object - sphere->center;
    matrix4_copy(&tm, &sphere->transform);
    _MM_TRANSPOSE4_PS(tm.row[0], tm.row[1], tm.row[2], tm.row[3]);
    normal = matrix4_mult_vec4(tm, normal);
    normal[3] = 0; 
    normal = vector_normalize(normal);
    return (normal);
}

bool  sphere_hit_test(t_ray *ray, t_object *sphere, float* t)
{
    t_vec4  sphere_to_ray;
    t_vec4  values;
    t_ray   ray_t;
    float   sqrtd;
    float   invd;

    ray_t = ray_transform(ray, sphere->transform);
    sphere_to_ray = ray_t.origin - sphere->center;
    values = (t_vec4){vector_dot_product(ray_t.direction, ray_t.direction),
                    2 * vector_dot_product(ray_t.direction, sphere_to_ray), 
                    vector_dot_product(sphere_to_ray, sphere_to_ray) - 1, 
                    0};
    values[3] = values[1] * values[1] - (4 * values[0] * values[2]);
    if (values[3] < 0)
        return (false);
    sqrtd = sqrt(values[3]);
    invd = 1.f / (2 * (values[0]));
    t[0] = (-values[1] - sqrtd) * invd;
    t[1] = (-values[1] + sqrtd) * invd;
    return (true);
}

/* float hit_sphere_geom(t_ray *ray, t_object *sphere)
{
    t_vec4  oc;
    bool    inside;
    float   lensq;
    float   tca;
    float   t2hc;
    float   r2;

    r2 = obj->diameter * 0.5 * obj->diameter * 0.5;
    oc = ray->direction - obj->center;
    lensq = vector_len_squared(oc);
    inside = lensq < r2;
    tca = vector_dot_product(oc, ray->direction);
    if (tca < 0 && !inside)
        return (0);
    t2hc = r2 - (lensq - (tca * tca));
    if (t2hc < 0)
        return (0);
    if (inside)
        return (tca + sqrt(t2hc));
    return (tca - sqrt(t2hc));
} */