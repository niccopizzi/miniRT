#include "intersections.h"

t_intersect*    hit(const t_da *intersections)
{
    t_intersect*    it;
    size_t          size;
    size_t          n;
    t_intersect*    closest;

    n = intersections->size;
    if (!n)
        return (NULL);
    it = (t_intersect *)intersections->data;
    closest = it;
    size = 0;
    while (size < n)
    {
        if (it[size].t > 0 && it[size].t < closest->t)
            closest = it;
        size++;
    }
    if (closest->t < 0)
        return (NULL);
    return (closest);
}

void    intersections_find(const t_world *world, t_ray *ray, t_da *intersections)
{
    t_object    *ptr;
    t_intersect intersection;
    float       t[2];

    ptr = (t_object *)world->objects.data;
    for (int i = 0; i < world->objects.size; i++)
    {
        if (sphere_hit_test(ray, &ptr[i], t))
        {
            intersection.t = fmin(t[0], t[1]);
            intersection.intersected = ptr;
            da_append(intersections, &intersection);
            intersection.t = fmax(t[0], t[1]);
            da_append(intersections, &intersection);
        }
    }
}

void    intersections_sort(t_da* intersections)
{
    t_intersect* ptr;
    size_t       i;
    size_t       j;
    size_t       n;

    i = 0;
    ptr = (t_intersect *)intersections->data;
    n = intersections->size;
    while (i < n - 1)
    {
        j = i + 1;
        while (j < n)
        {
            if (ptr[j].t < ptr[i].t)
                da_swap(intersections, i, j);
            j++;
        }       
        i++; 
    }
}
