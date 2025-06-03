#include "world.h"
#include "objects.h"

void    free_world_data(t_world* world)
{
    if (world->objects.data)
    {
        free(world->objects.data);
        world->objects.data = NULL;
    }
    if (world->lights.data)
    {
        free(world->lights.data);
        world->lights.data = NULL;
    }
}

void    world_setup(t_world* world)
{
    world->get_color = calculate_color;
    camera_setup(&world->cam);
}
