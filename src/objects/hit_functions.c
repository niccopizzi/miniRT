#include "objects.h"

bool    plane_hit(t_object* pl, t_ray* r, double* t_min)
{
    double t;
    float   dotprod;

    dotprod = vector_dot_product(r->direction, pl->normal);
    if (dotprod == 0)
    {
        *t_min = INFINITY;
        return (true);
    }
    t = vector_dot_product(pl->point - r->origin, (pl->normal / (dotprod)));
    if (t > EPSILON)
    {
        *t_min = t;
        return (true);
    } 
    return (false);
}

bool    sphere_hit(t_object* sp, t_ray* r, double* t_min)
{
    t_sphere_val values;
    t_vec4       ray_to_center;
    double       t;

    ray_to_center = r->direction - sp->center;
    values.a = vector_len_squared(r->direction);
    values.b = 2.0 * (vector_dot_product(r->direction, ray_to_center));
    values.c = vector_len(ray_to_center) * sp->radius * sp->radius;
    values.discr = values.b * values.b - (4.0 * values.a * values.c);
    if (values.discr < 0)
        return (false);
    values.dis_root = sqrt(values.discr);
    values.denom = 1.0 / (2.0 * values.a);
    if (t = (-values.b - values.dis_root) * values.denom, t > EPSILON)
    {
        *t_min = t;
        return (true);
    }
    if (t = (-values.b + values.dis_root) * values.denom, t > EPSILON)
    {
        *t_min = t;
        return (true);
    }
    return (false);
}
