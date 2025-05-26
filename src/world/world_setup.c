#include "world.h"
#include "objects.h"

void    father_setup(t_object* ptr, size_t size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
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
    t_object*   ptr;
    size_t      i;
    size_t      size;

    ptr = (t_object* )world->objects.data;
    size = world->objects.size;
    i = 0;
    while (i < size)
    {
        object_material_setup(&ptr[i]);
        i++;
    }
    father_setup(ptr, size);
    camera_setup(&world->cam);
}
