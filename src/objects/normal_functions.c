/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:23:21 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:35:51 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "render.h"

t_vec4	sphere_normal(const t_object *obj, t_shading *info)
{
	return ((info->point_hit - obj->point) / obj->radius);
}

t_vec4	plane_normal(const t_object *obj, t_shading *info)
{
	(void)info;
	return (obj->normal);
}

t_vec4	cylinder_normal(const t_object *obj, t_shading *info)
{
	t_vec4	v;
	t_vec4	proj;

	v = info->point_hit - obj->point;
	proj = vector_dot_product(v, obj->axis) * obj->axis;
	return ((v - proj) / obj->radius);
}

t_vec4	cone_normal(const t_object *obj, t_shading *info)
{
	t_vec4	v;
	t_vec4	proj;

	v = info->point_hit - obj->point;
	proj = vector_dot_product(v, obj->axis) * obj->axis;
	return ((v - proj) / obj->radius);
}
