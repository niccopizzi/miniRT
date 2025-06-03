#include "objects.h"
#include "world.h"

#define BIAS (float)0.00001

double  fmin_positive(double x, double y)
{
    if (x < 0 || y < 0)
        return (fmax(x, y));
    return (fmin(x, y));  
}

t_object    bottom_cap_create(t_object* obj)
{
    t_object    bottom_cap;

    bottom_cap.color = obj->color;
    bottom_cap.point = obj->point - obj->axis * obj->half_height;
    bottom_cap.normal = -obj->axis;
    bottom_cap.radius = obj->radius;
    bottom_cap.r2 = obj->r2;
    bottom_cap.hit = disk_hit;
    bottom_cap.normal_get = plane_normal;
    bottom_cap.map = plane_map;
    bottom_cap.checkered = obj->checkered;

    return (bottom_cap);
}

t_object    top_cap_create(t_object* obj)
{
    t_object    top_cap;

    top_cap.color = obj->color;
    top_cap.point = obj->point + obj->axis * obj->half_height;
    top_cap.normal = obj->axis;
    top_cap.radius = obj->radius;
    top_cap.r2 = obj->r2;
    top_cap.hit = disk_hit;
    top_cap.normal_get = plane_normal;
    top_cap.map = plane_map;
    top_cap.checkered = obj->checkered;

    return (top_cap);
}

bool    cone_add_to_objects(t_object* co, t_world* world)
{
    t_object    bottom_cap;

    bottom_cap = bottom_cap_create(co);

    return (da_append(&world->objects, &bottom_cap) 
            && da_append(&world->objects, co)); 
}

bool    cylinder_add_to_objects(t_object* cy, t_world* world)
{
    t_object    bottom_cap;
    t_object    top_cap;

    bottom_cap = bottom_cap_create(cy);
    top_cap = top_cap_create(cy);
    
    return (da_append(&world->objects, &bottom_cap) 
                && da_append(&world->objects, &top_cap) 
                && da_append(&world->objects, cy));
}
