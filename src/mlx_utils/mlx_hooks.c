/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:21:43 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 15:22:48 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	window_close(t_ptrs *ptrs)
{
	mlx_destroy_image(ptrs->mlx_ptr, ptrs->img->img_ptr);
	mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
	mlx_destroy_display(ptrs->mlx_ptr);
	free(ptrs->mlx_ptr);
	free_world_data(ptrs->world);
	exit(EXIT_SUCCESS);
}

int	keys_hook(int key, t_ptrs *ptrs)
{
	if (key == XK_Escape)
		window_close(ptrs);
	else if (key == XK_r)
		return (reload(ptrs));
	else if (key == XK_space)
		toggle_antialiasing(ptrs, ptrs->world);
	else if (key == XK_Tab)
		handle_tab_key(ptrs, ptrs->world);
	else if (key == XK_l)
		handle_l_key(ptrs, ptrs->world);
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
		handle_cam_movement(key, &ptrs->world->cam, ptrs);
	else if (key == XK_Left || key == XK_Right || key == XK_Up
		|| key == XK_Down)
		handle_cam_rotation(key, &ptrs->world->cam, ptrs);
	else if (key == XK_minus || key == KEY_MINUS || key == XK_plus
		|| key == KEY_PLUS)
		handle_cam_zoom(key, &ptrs->world->cam, ptrs);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_ptrs *ptrs)
{
	if (button == 1 && ptrs->world->light_moving >= 0)
	{
		handle_light_movement(x, y, ptrs->world);
		render_scene(ptrs, ptrs->world);
	}
	return (0);
}

void	hooks_set_up(t_ptrs *ptrs)
{
	mlx_hook(ptrs->win_ptr, 17, 0, window_close, ptrs);
	mlx_key_hook(ptrs->win_ptr, keys_hook, ptrs);
	mlx_mouse_hook(ptrs->win_ptr, mouse_hook, ptrs);
}
