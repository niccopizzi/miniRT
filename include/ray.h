/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:40:04 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 13:41:35 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "matrix.h"
# include <limits.h>

# define START_VAL 100000

typedef enum e_rtype
{
	PRIMARY,
	SHADOW,
	REFLECTIVE,
	REFRACTIVE,
}				t_rtype;

typedef struct s_ray
{
	t_rtype		type;
	t_vec4		direction;
	t_point4	origin;
}				t_ray;

t_ray			ray_create(t_point4 origin, t_vec4 direction, t_rtype type);
t_point4		ray_at(const t_ray *ray, float time);
t_ray			ray_transform(const t_ray *ray, const t_mat4 *tm);
t_ray			ray_reflect(const t_ray *ray, const t_vec4 normal, t_point4 p);
t_ray			ray_refract(const t_ray *ray, const t_vec4 normal, t_point4 p,
					float ratio);

#endif // RAY_H