#include "render.h"

/*Function to loop over all the objects and find the closest intersection point
this value (t) will then be used to compute the color of the pixel*/
double      find_hit(t_ray* ray, t_object** ptr, const t_world* world)
{
    t_object* obj_ptr;
    size_t    obj_size;
    size_t    i;
    double    t;
    double    t_min;

    obj_ptr = (t_object*)world->objects.data;
    obj_size = world->objects.size;
    i = 0;
    t_min = START_VAL;
    while (i < obj_size)
    {
        if ((obj_ptr[i].hit(&obj_ptr[i], ray, &t)) && (t < t_min))
        {
                t_min = t;
                *ptr = obj_ptr + i; //Record the object that was hit, need to store this information for when
                                //we go to compute the color 
        }
        i++;
    }
    return (t_min);
}

t_color     ray_trace(t_ray *ray, const t_world* world)
{
    t_color     ret_color;
    t_object*   obj_hit;
    double      t;

    obj_hit = NULL;
    ret_color = world->a_light.color;
    t = find_hit(ray, &obj_hit, world);
    if (obj_hit != NULL) //The ray hit something, we need to compute the color of the pixel
        ret_color = phong_lightning(obj_hit, &world->light_src, ray, 
                        obj_hit->norm(obj_hit, *ray, t));
    //Other surface properties can be checked here and added from there
    return (ret_color);
}