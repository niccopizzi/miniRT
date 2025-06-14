/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_functions_utils_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:22:48 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:36:22 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

inline bool	check_t(double t, double *t_min)
{
	if (t > EPSILON)
	{
		*t_min = t;
		return (true);
	}
	return (false);
}

bool	is_inside_cy(const t_point4 ray_at, const t_object *obj)
{
	float	dotprod;

	dotprod = vector_dot_product(ray_at - obj->point, obj->axis);
	return (dotprod > -obj->half_height + EPSILON && dotprod < obj->half_height
		- EPSILON);
}

bool	is_inside_co(const t_point4 ray_at, const t_object *obj)
{
	float	dotprod;

	dotprod = vector_dot_product(ray_at - obj->point, obj->axis);
	return (dotprod > -obj->half_height && dotprod < EPSILON);
}
