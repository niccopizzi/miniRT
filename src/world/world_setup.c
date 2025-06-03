#include "world.h"
#include "objects.h"

/*
 void   object_material_setup(t_object* obj, t_material  material)
{
    obj->material = material;
}
*/

/* void    objects_setup(t_object* ptr, size_t size)
{
    size_t  i;
    t_mat4  to_world;

    i = 0;
    while (i < size)
    {
        to_world = 
        (ptr + i)->to_obj = matrix4_inv
        i++;
    }
}  */

void    free_world_data(t_world* world)
{
    if (world->objects.data)
    {
        free(world->objects.data);
        world->objects.data = NULL;
    }
    if (world->light.data)
    {
        free(world->light.data);
        world->light.data = NULL;
    }
}

void    world_setup(t_world* world)
{
    world->get_color = calculate_color;
    //objects_setup((t_object* )world->objects.data, world->objects.size);
    camera_setup(&world->cam);
}
