#include "objects.h"

inline bool check_t(double t, double *t_min)
{
    if (t > EPSILON)
    {
        *t_min = t;
        return (true);
    }
    return (false);
}

bool    plane_hit(t_object* pl, t_ray* r, double* t_min)
{
    float   dotprod;

    dotprod = vector_dot_product(r->direction, pl->normal);
    if (dotprod == 0) /*check if dot product is 0 to avoid division by 0 later*/
    {
        *t_min = INFINITY;
        return (true);
    }
    return (check_t(
                vector_dot_product(
                    pl->point - r->origin, pl->normal) / dotprod, t_min));
}

bool    sphere_hit(t_object* sp, t_ray* r, double* t_min)
{
    t_sp_val v;
    t_vec4       oc;

    oc = r->origin - sp->center;
    v.a = vector_dot_product(r->direction, r->direction);
    v.b = 2.0 * (vector_dot_product(r->direction, oc));
    v.c = vector_dot_product(oc, oc) - sp->radius * sp->radius;
    v.discr = v.b * v.b - (4.0 * v.a * v.c);
    if (v.discr < 0)
        return (false);
    v.discr = sqrt(v.discr);
    v.denom = 1.0 / (2.0 * v.a);
    v.t = (-v.b - v.discr) * v.denom;
    if (check_t(v.t, t_min))
        return (true);
    v.t = (-v.b + v.discr) * v.denom;
    return (check_t(v.t, t_min));
}

inline  void compute_cy_values(t_cy_val* v, t_object* cy, t_ray* r)
{
    v->ba = cy->axis * cy->height;
    v->oc = r->origin - cy->bp;
    v->baba = vector_dot_product(v->ba, v->ba);
    v->bard = vector_dot_product(v->ba, r->direction);
    v->baoc = vector_dot_product(v->ba, v->oc);
    v->k2 = v->baba - v->bard * v->bard;
    v->k1 = v->baba * 
            vector_dot_product(v->oc, r->direction) - v->baoc * v->bard;
    v->k0 = v->baba * vector_dot_product(v->oc, v->oc) - 
                    v->baoc * v->baoc - cy->radius * cy->radius * v->baba;
    v->h = v->k1 * v->k1 - v->k2 * v->k0;
}
/* 
bool    cylinder_hit(t_object* cy, t_ray* r, double *t_min)
{
    t_cy_val    v;

    compute_cy_values(&v, cy, r);
    if (v.h < 0)
        return (false);
    v.h = sqrt(v.h);
    if (fabs(v.k2) > EPSILON)
    {
        v.t = (-v.k1 - v.h) / v.k2;
        v.y = v.baoc + v.t * v.bard;
        if (v.y > 0 && v.y < v.baba)
            return (check_t(v.t, t_min));
    }
    if (fabs(v.bard) > EPSILON)
    {
        if (v.y < 0)
            v.t = -v.baoc / v.bard;
        else
            v.t = (v.baba - v.baoc) / v.bard;
        if (fabs(v.k1 + v.k2 * v.t) < v.h)
            return (check_t(v.t, t_min));
    }
    return (false);
} */

//Working for inifite cylinder
 bool    cylinder_hit(t_object* cy, t_ray* r, double *t_min)
{
    t_vec4          oc;
    t_inf_cy_val    v;

    oc = r->origin - cy->bp;
    v.card = vector_dot_product(r->direction, cy->axis);
    v.caoc = vector_dot_product(cy->axis, oc);
    v.a = 1.0 - v.card * v.card;
    v.b = vector_dot_product(oc, r->direction) - v.caoc * v.card;
    v.c = vector_dot_product(oc, oc) - v.caoc * v.caoc - cy->radius * cy->radius;
    v.h = v.b * v.b - v.a * v.c;
    if (v.h < 0)
        return (false);
    v.h = sqrt(v.h);
    v.t = (- v.b - v.h) / v.a;
    if (check_t(v.t, t_min))
        return (true);
    v.t = (-v.b + v.h) / v.a;
    if (check_t(v.t, t_min))
        return (true);
    //return (cylinder_cap_hit)
    return (false);
}
