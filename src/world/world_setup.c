#include "world.h"
#include "objects.h"

void   object_material_setup(t_object* obj, t_vec4  material)
{
    obj->material = material;
}

void    objects_setup(t_object* ptr, size_t size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        object_material_setup(&ptr[i], material_get_plastic());
        if (ptr[i].father == NULL)
        {
            ptr[i - 2].father = &ptr[i];
            ptr[i - 1].father = &ptr[i];
        }
        ptr[i].father = &ptr[i];
        i++;
    }
}

void    world_setup(t_world* world)
{
    world->get_color = calculate_color;
    objects_setup((t_object* )world->objects.data, world->objects.size);
    camera_setup(&world->cam);
}
