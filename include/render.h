/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:41:42 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 13:46:02 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "mlx_utils.h"
# include "objects.h"
# include "random.h"
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

# define MAX_DEPTH 5

# define BIAS 0.0001

typedef struct s_shading
{
	bool		front_face;
	float		t;
	float		distance;
	t_point4	point_hit;
	t_vec4		normal_at;
	t_vec4		light_dir;
	t_color		ambient;
	const t_ray	*hitting_ray;
	t_object	*obj_hit;

}				t_shading;

void			render_scene(t_ptrs *ptrs, t_world *world);
t_color			ray_trace(const t_ray *ray, const t_world *world);
void			get_shading_info(t_shading *shade_info, const t_ray *ray,
					const t_world *world);
t_color			color_at_hit(t_shading *info, const t_light *l);
t_color			calculate_color(int x, int y, const t_world *world, t_ray *r);
bool			apply_checker(float u, float v);

#endif // RENDER.H