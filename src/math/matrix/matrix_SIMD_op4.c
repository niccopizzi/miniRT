/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_SIMD_op4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:20:05 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 15:28:18 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	matrix4_rodrigues_rot(t_vec4 axis, double angle)
{
	t_mat4	r;
	float	st;
	float	ct;
	float	ax[3];

	st = sin(angle);
	ct = cos(angle);
	ax[0] = axis[0];
	ax[1] = axis[1];
	ax[2] = axis[2];
	r.row[0] = (t_vec4){ct + ax[0] * ax[0] * (1 - ct), ax[0] * ax[1]
		* (1 - ct) - ax[2] * st, ax[0] * ax[2] * (1 - ct) + ax[1] * st,
		0};
	r.row[1] = (t_vec4){ax[1] * ax[0] * (1 - ct) + ax[2] * st, ct
		+ ax[1] * ax[1] * (1 - ct), ax[1] * ax[2] * (1 - ct) - axis[0]
		* st, 0};
	r.row[2] = (t_vec4){ax[2] * ax[0] * (1 - ct) - ax[1] * st, ax[2]
		* ax[1] * (1 - ct) + ax[0] * st, ct + ax[2] * ax[2] * (1 - ct),
		0};
	r.row[3] = (t_vec4){0, 0, 0, 1};
	return (r);
}

t_mat4	matrix4_to_world(t_vec4 axis, t_vec4 origin)
{
	t_mat4	to_world;
	t_vec4	tmp_up;

	to_world = matrix4_identity();
	tmp_up = (t_vec4){0, 1, 0, 0};
	if (fabs(vector_dot_product(tmp_up, axis)) > 1.0f - EPSILON)
		tmp_up = (t_vec4){0, 0, 1, 0};
	to_world.row[0] = vector_normalize(vector_cross_prod(axis, tmp_up));
	to_world.row[1] = vector_normalize(vector_cross_prod(axis,
				to_world.row[0]));
	to_world.row[2] = axis;
	to_world.row[3] = origin;
	return (to_world);
}

t_mat4	matrix4_scaling(float tx, float ty, float tz)
{
	t_mat4	m;

	m = matrix4_identity();
	m.row[0][0] = tx;
	m.row[1][1] = ty;
	m.row[2][2] = tz;
	return (m);
}
