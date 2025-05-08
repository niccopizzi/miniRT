#include "mlx_utils.h"
#include "light.h"

int window_close(t_ptrs *ptrs)
{
    mlx_destroy_image(ptrs->mlx_ptr, ptrs->img->img_ptr);
    mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
    mlx_destroy_display(ptrs->mlx_ptr), free(ptrs->mlx_ptr);
    free(ptrs->world->objects.data);
    exit(EXIT_SUCCESS);
}

void    hooks_set_up(t_ptrs *ptrs)
{
    mlx_hook(ptrs->win_ptr, 17, 0, window_close, ptrs);
}
