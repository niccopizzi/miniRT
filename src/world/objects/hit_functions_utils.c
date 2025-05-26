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

bool    is_inside_cap(const t_point4 ray_at, const t_object* cy)
{
    float   dotprod;

    dotprod = vector_dot_product(ray_at - cy->center, cy->axis);
    return (dotprod > -cy->half_height && dotprod < cy->half_height);
        
}