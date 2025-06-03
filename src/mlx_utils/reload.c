#include "mlx_utils.h"
#include "objects.h"

int     reload(t_ptrs* ptrs)
{
    t_world     brave_new_world;

    ft_bzero(&brave_new_world, sizeof(t_world));
    if (!da_init(&brave_new_world.objects, OBJECTS_CAPACITY, sizeof(t_object)))
        return (printf("Malloc error"), 2);
    if (!da_init(&brave_new_world.lights, LIGHTS_CAPACITY, sizeof(t_light)))
        return (free(brave_new_world.objects.data), printf("Malloc error"), 2);
    if(!is_valid_file(ptrs->filename, &brave_new_world))
        return (free_world_data(&brave_new_world), 3);
    world_setup(&brave_new_world);
    free_world_data(ptrs->world);
    ft_memcpy(ptrs->world, &brave_new_world, sizeof(t_world));
    render_scene(ptrs, ptrs->world);
    return (0);      
}