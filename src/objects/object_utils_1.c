#include "objects.h"
#include "world.h"

bool    cone_add_to_objects(t_object* co, t_world* world)
{
    t_object    bottom_cap;

    bottom_cap.color = co->color;
    bottom_cap.point = co->center - co->axis * co->half_height;
    bottom_cap.normal = -co->axis;
    bottom_cap.radius = co->radius;
    bottom_cap.material = co->material;  
    bottom_cap.hit = disk_hit;
    bottom_cap.normal_get = plane_normal;
    bottom_cap.father = co;
    return (da_append(&world->objects, &bottom_cap) 
            && da_append(&world->objects, co)); 
}

bool    cylinder_add_to_objects(t_object* cy, t_world* world)
{
    t_object    bottom_cap;
    t_object    top_cap;

    bottom_cap.color = cy->color;
    bottom_cap.point = cy->center - cy->axis * cy->half_height;
    bottom_cap.normal = -cy->axis;
    bottom_cap.radius = cy->radius;
    bottom_cap.material = cy->material;
    bottom_cap.hit = disk_hit;
    bottom_cap.normal_get = plane_normal;
    bottom_cap.father = cy;
    top_cap.color = cy->color;
    top_cap.point = cy->center + cy->axis * cy->half_height;
    top_cap.normal = cy->axis;
    top_cap.radius = cy->radius;
    top_cap.material = cy->material;
    top_cap.hit = disk_hit;
    top_cap.normal_get = plane_normal;
    top_cap.father = cy;
    
    return (da_append(&world->objects, &bottom_cap) 
                && da_append(&world->objects, &top_cap) 
                && da_append(&world->objects, cy));
}
