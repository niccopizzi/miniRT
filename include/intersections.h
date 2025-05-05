#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "objects.h"
#include "world.h"
#include "../lib/minift/include/minift.h"

typedef struct s_intersect
{
    float       t;
    t_object*   intersected;
     
}   t_intersect;

void            intersections_find(const t_world *world, t_ray *ray, t_da *intersections);
void            intersections_sort(t_da* intersections);
t_intersect*    hit(const t_da *intersections);
#endif  //INTERSECTIONS_H