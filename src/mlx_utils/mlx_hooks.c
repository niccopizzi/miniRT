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
/* 

int mouse_hooks(int button, int x, int y, t_ptrs *ptrs)
{
    (void)x;
    (void)y;
    if (button == 1)
        draw_plus_button(ptrs, WIDTH - 100, 100 , 0x5500FF);
    mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, ptrs->img->img_ptr, 0, 0);
    return (0);
} */

int hooks_key(int key, t_ptrs *ptrs)
{
    if (key == XK_Escape)
        window_close(ptrs);
    if (key == XK_Down || key == XK_Up || key == XK_Left || key == XK_Right)
    {    
        light_move(ptrs, key);
    }
    return (0);
}

void    hooks_set_up(t_ptrs *ptrs)
{
    mlx_hook(ptrs->win_ptr, 17, 0, window_close, ptrs);
   // mlx_mouse_hook(ptrs->win_ptr, mouse_hooks, ptrs);
    mlx_key_hook(ptrs->win_ptr, hooks_key, ptrs);
}
