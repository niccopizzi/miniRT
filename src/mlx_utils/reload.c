#include "mlx_utils.h"
#include "objects.h"

int     reload(t_ptrs* ptrs)
{
    t_world     brave_new_world;

    ft_bzero(&brave_new_world, sizeof(t_world));
    if (!da_init(&brave_new_world.objects, 20, sizeof(t_object)))
        return (printf("Malloc error"), 2);
    if(!is_valid_file(ptrs->filename, &brave_new_world))
        return (free(brave_new_world.objects.data), 3);
    world_setup(&brave_new_world);
    free(ptrs->world->objects.data);
    ft_memcpy(ptrs->world, &brave_new_world, sizeof(t_world));
    render_scene(ptrs, ptrs->world);
    return (0);      
}