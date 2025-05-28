#include "render.h"

/*Function to loop over all the objects and find the closest intersection point
this value (t) will then be used to compute the color of the pixel*/
bool      find_hit(const t_ray* ray, const t_world* world, t_shading* s)
{
    t_object* obj_ptr;
    size_t    obj_size;
    size_t    i;
    double    t_min;

    obj_ptr = (t_object*)world->objects.data;
    obj_size = world->objects.size;
    i = 0;
    while (i < obj_size)
    {
        t_min = START_VAL;
        if ((obj_ptr[i].hit(&obj_ptr[i], ray, &t_min)) && (t_min < s->t))
        {
                s->t = t_min;
                s->obj_hit = obj_ptr + i; //Record the object that was hit, need to store this information for when
                                //we go to compute the color 
        }
        i++;
    }
    return (s->obj_hit != NULL);
}

bool        is_in_shadow(const t_point4 origin, const t_world* world, 
                            t_shading* info)
{
    t_ray       shadow_ray;
    t_object*   obj_ptr;
    size_t      obj_size;
    size_t      i;
    double      t;

    obj_ptr = (t_object*)world->objects.data;
    obj_size = world->objects.size;
    i = 0;
    shadow_ray = ray_create(origin, (info->light_dir), SHADOW);
    while (i < obj_size)
    {
        t = START_VAL;
        if (obj_ptr[i].hit(&obj_ptr[i], &shadow_ray, &t) 
                && t < info->distance)
            return (true);
        i++;
    }
    return (false);
}

t_color     ray_trace(const t_ray* ray, const t_world* world, int depth)
{
    t_color     ret_color;
    t_shading   info;

    if (depth > MAX_DEPTH)
        return (world->background);
    info.obj_hit = NULL;
    info.t = START_VAL;
    ret_color = world->background;
    if (find_hit(ray, world, &info))
    {
        get_shading_info(&info, ray, &world->lights);
        if (is_in_shadow(info.hit_point + info.normal_at * BIAS, world,
                &info))
            return (vector_from_float(0.0f));
        ret_color = color_at_hit(&info, &world->lights, world);
    }
    return (vector_clamp(ret_color, 0, 1));
}
