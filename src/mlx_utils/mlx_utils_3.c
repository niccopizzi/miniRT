/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:22:19 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/15 01:12:01 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	handle_l_key(t_ptrs *ptrs, t_world *world)
{
	if (world->light_moving == -1)
		world->light_moving = 0;
	else
		world->light_moving = -1;
	render_scene(ptrs, ptrs->world);
}

void	handle_tab_key(t_ptrs *ptrs, t_world *world)
{
	if (world->light_moving == -1 || world->lights.size == 1)
		return ;
	world->light_moving = (world->light_moving + 1) % world->lights.size;
	render_scene(ptrs, ptrs->world);
}

void	toggle_antialiasing(t_ptrs *ptrs, t_world *world)
{
	if (world->get_color == calculate_color)
		world->get_color = sample_pixel;
	else
		world->get_color = calculate_color;
	render_scene(ptrs, ptrs->world);
}

void	handle_light_movement(int x, int y, t_world *world)
{
	t_light		*light;
	t_vec4		dir;
	t_point4	p;
	float		t;

	light = (t_light *)world->lights.data;
	light += world->light_moving;
	dir = vector_normalize((t_vec4){get_camera_x(x, world->cam.scale),
			get_camera_y(y, world->cam.scale), world->cam.forward[2], 0});
	dir = matrix4_mult_vec4(&world->cam.to_world, dir);
	t = (light->pos[2] - world->cam.origin[2]) / dir[2];
	p = world->cam.origin + t * dir;
	light->pos[0] = -p[0];
	light->pos[1] = -p[1];
}
