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

bool  sphere_hit_test(t_ray *ray, t_object *sphere, t_hit *hit_record, 
                        float t_min, float t_max)
{
    t_vec4 oc;
    float   values[4];  /*a h c d*/
    float   droot;
    float   root;

    oc = sphere->center - ray->direction;
    values[0] = vector_len_squared(ray->direction);
    values[1] = vector_dot_product(ray->direction, oc);
    values[2] = vector_len_squared(oc) - (sphere->radius * sphere->radius);
    values[3] = values[1] * values[1] - values[0] * values[2];
    if (values[3] < 0)
        return (false);
    droot = sqrt(values[3]);
    root = (values[1] - droot) / values[0];
    if (root <= t_min || root >= t_max)
    {
        root = (values[1] + droot) / values[0];
        if (root <= t_min || root >= t_max)
            return (false);
    }
    hit_record->t = root;
    hit_record->p = ray_at(*ray, root);
    hit_set_face_normal(ray, hit_record, sphere_normal_at(sphere, hit_record->p));
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