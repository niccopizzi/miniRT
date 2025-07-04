/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:17:49 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 13:20:58 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "vectors.h"
# include <stdio.h>

# define TO_RAD 0.0174533

typedef union u_mat4
{
	t_vec4		row[4];
	float		m[4][4];
}				t_mat4;

typedef union u_mat2
{
	t_vec4		vec;
	float		arr[4];
}				t_mat2;

typedef t_mat4	t_mat3;

t_mat4			matrix4_identity(void);
t_mat4			matrix4_transpose(t_mat4 m);
t_mat4			matrix4_mult_mat4(const t_mat4 *m1, const t_mat4 *m2);
t_mat4			matrix4_invert(const t_mat4 *m);
t_mat3			matrix4_submatrix(const t_mat4 *m, int row, int col);
t_vec4			matrix4_mult_vec4(const t_mat4 *m, t_vec4 vec);
void			matrix4_copy(t_mat4 *dest, const t_mat4 *src);
float			matrix4_det(const t_mat4 *m);
bool			matrix4_compare_eq(const t_mat4 *m1, const t_mat4 *m2);

t_mat4			matrix4_shearing(const float *values);
t_mat4			matrix4_rotate_x(float rad);
t_mat4			matrix4_rotate_y(float rad);
t_mat4			matrix4_rotate_z(float rad);
t_mat4			matrix4_translate(float tx, float ty, float tz);
t_mat4			matrix4_scaling(float tx, float ty, float tz);
t_mat4			matrix4_rodrigues_rot(t_vec4 axis, double angle);
t_mat4			matrix4_to_world(t_vec4 axis, t_vec4 origin);

t_mat2			matrix3_submatrix(const t_mat3 *m, int row, int col);
float			matrix3_minor(const t_mat3 *m, int row, int col);
float			matrix3_cofactor(const t_mat3 *m, int row, int col);
float			matrix3_det(const t_mat3 *m);
#endif // MATRIX_H
