/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_SIMD_op3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:20:56 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:35:13 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

inline bool	vector_compare_eq(t_vec4 vector1, t_vec4 vector2)
{
	return (vector_in_range(vector1 - vector2, -EPSILON, EPSILON));
}

inline bool	vector_compare_lt(t_vec4 vector1, t_vec4 vector2)
{
	return (_mm_movemask_ps(_mm_cmplt_ps(vector1, vector2)) != 0);
}

inline bool	vector_compare_gt(t_vec4 vector1, t_vec4 vector2)
{
	return (_mm_movemask_ps(_mm_cmpgt_ps(vector1, vector2)) != 0);
}

inline t_vec4	vector_from_float(float a)
{
	return (_mm_load1_ps(&a));
}

inline t_vec4	vector_from_array(const float *array)
{
	return (_mm_load_ps(array));
}
