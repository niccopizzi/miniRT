/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_SIMD_op2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:20:48 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:35:11 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline t_vec4	vector_normalize(t_vec4 vector)
{
	float	len;

	len = vector_len(vector);
	if (len == 0)
		return (_mm_set1_ps(0));
	return (vector * (1 / len));
}

t_vec4	vector_cross_prod(t_vec4 vector1, t_vec4 vector2)
{
	return ((t_vec4){vector1[1] * vector2[2] - vector1[2] * vector2[1],
		vector1[2] * vector2[0] - vector1[0] * vector2[2], vector1[0]
		* vector2[1] - vector1[1] * vector2[0], 0});
}

inline t_point4	lerp(t_point4 p1, t_point4 p2, float a)
{
	return (_mm_add_ps(p1 * (1 - a), p2 * (a)));
}

inline bool	vector_in_range(t_vec4 vector, float min, float max)
{
	return ((_mm_movemask_ps(_mm_cmp_ps(vector, _mm_load1_ps(&min),
					_CMP_LT_OS))) == 0 && _mm_movemask_ps(_mm_cmp_ps(vector,
				_mm_load1_ps(&max), _CMP_GT_OS)) == 0);
}
