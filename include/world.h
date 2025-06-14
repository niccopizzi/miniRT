/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:48:31 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:02:07 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../lib/minift/include/minift.h"
# include "ray.h"

# define OBJECTS_CAPACITY 20
# define LIGHTS_CAPACITY 5

typedef struct s_cam
{
	float				fov;
	float				scale;
	t_mat4				to_world;
	t_point4			origin;
	t_vec4				forward;
	t_vec4				up;
	t_vec4				right;
}						t_cam;

typedef struct s_light
{
	float				brightness;
	t_color				color;
	t_color				effective;
	t_point4			pos;
	bool				move;
}						t_light;

typedef struct s_world	t_world;

struct					s_world
{
	int					light_moving;
	t_color				(*get_color)(int x, int y, const t_world *, t_ray *);
	t_color				background;
	t_color				ambient;
	t_cam				cam;
	t_da				lights;
	t_da				objects;
};

t_mat4					camera_to_world(t_cam *cam);
void					camera_setup(t_cam *c);
void					world_setup(t_world *world);
float					get_camera_x(int x, float scale);
float					get_camera_y(int y, float scale);

void					free_world_data(t_world *world);

// Forward declaration

t_color					calculate_color(int x, int y, const t_world *world,
							t_ray *r);
t_color					sample_pixel(int x, int y, const t_world *world,
							t_ray *r);
#endif
