#include "render.h"

/*Function to loop over all the objects and find the closest intersection point
this value (t) will then be used to compute the color of the pixel*/
bool      find_hit(const t_ray* ray, t_object** ptr, double *t, 
                    const t_world* world)
{
    t_object* obj_ptr;
    size_t    obj_size;
    size_t    i;
    double    t_min;

    obj_ptr = (t_object*)world->objects.data;
    obj_size = world->objects.size;
    i = 0;
    t_min = START_VAL;
    while (i < obj_size)
    {
        if ((obj_ptr[i].hit(&obj_ptr[i], ray, &t_min)) && (t_min < *t))
        {
                *t = t_min;
                *ptr = obj_ptr + i; //Record the object that was hit, need to store this information for when
                                //we go to compute the color 
        }
        i++;
    }
    return (*ptr != NULL);
}

bool        is_in_shadow(const t_point4 origin, const t_world* world, 
                            t_object** to_test)
{
    t_ray       shadow_ray;
    t_vec4      light_dir;
    t_object*   obj_ptr;
    size_t      obj_size;
    size_t      i;
    double      t;
    float       t_light;

    obj_ptr = (t_object*)world->objects.data;
    obj_size = world->objects.size;
    i = 0;
    light_dir = world->light_src.pos - origin;
    t_light = vector_len(light_dir);
    shadow_ray = ray_create(origin, vector_normalize(light_dir), SHADOW);
    t = START_VAL;
    while (i < obj_size)
    {
        if (obj_ptr[i].father != *to_test &&
                obj_ptr[i].hit(&obj_ptr[i], &shadow_ray, &t) && t < t_light)
            return (true);
        i++;
    }
    return (false);
}

t_color     ray_trace(const t_ray* ray, const t_world* world, int depth)
{
    t_color     ret_color;
    t_vec4      normal_at;
    t_object*   obj_hit;
    double      t;

    if (depth > MAX_DEPTH)
        return (vector_from_float(0.0f));
    obj_hit = NULL;
    t = START_VAL;
    ret_color = vector_from_float(0.0f);
    if (find_hit(ray, &obj_hit, &t, world))
    {
        normal_at = obj_hit->normal_get(obj_hit, ray, t);
        if (is_in_shadow(ray_at(ray, t) + normal_at * BIAS, world, 
                        &obj_hit->father))
            return (vector_from_float(0.0f));
        ret_color = obj_hit->color;
        //phong_lightning(obj_hit, &world->light_src, ray, 
        //                                normal_at);
    }
    return (vector_clamp(ret_color, 0, 1));
}
