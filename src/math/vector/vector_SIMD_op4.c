/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_SIMD_op4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:21:03 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:35:07 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec4	vector_reflect(const t_vec4 to_reflect, const t_vec4 normal)
{
	return (to_reflect - (normal * 2 * vector_dot_product(to_reflect, normal)));
}

t_vec4	vector_refract(const t_vec4 to_refract, const t_vec4 normal,
		float ratio)
{
	t_vec4	r1;
	t_vec4	r2;
	float	theta;

	theta = fminf(vector_dot_product(-to_refract, normal), 1.0f);
	r1 = ratio * (to_refract + theta * normal);
	r2 = -sqrtf(1 - (vector_dot_product(r1, r1))) * normal;
	return (r1 + r2);
}

t_vec4	vector_clamp(t_vec4 v, float min, float max)
{
	size_t	index;

	index = 0;
	while (index < 4)
	{
		if (v[index] < min)
			v[index] = min;
		else if (v[index] > max)
			v[index] = max;
		index++;
	}
	return (v);
}
