#ifndef MATRIX_H
#define MATRIX_H

#include "vectors.h"
#include <stdio.h>

typedef union u_mat4
{
    t_vec4  row[4];
    float   m[4][4];
} t_mat4;

typedef union u_mat2
{
    t_vec4  vec;
    float   arr[4];
}   t_mat2;


typedef t_mat4  t_mat3;

void        matrix_print(t_mat4 id, int size, char *name);

t_mat4      matrix4_identity(void);
void        matrix4_transpose(t_mat4 m);
t_mat4      matrix4_mult_mat4(t_mat4 m1, t_mat4 m2);
t_mat4      matrix4_invert(t_mat4 m);
t_mat3      matrix4_submatrix(t_mat4 m, int row, int col);
t_vec4      matrix4_mult_vec4(t_mat4 m, t_vec4 vec);
void        matrix4_copy(t_mat4 *dest, t_mat4 *src);
float       matrix4_det(t_mat4 m);
bool        matrix4_compare_eq(t_mat4 m1, t_mat4 m2);


t_mat4      matrix4_view_transform(t_point4 from, t_vec4 forward, t_vec4 up);
t_mat4      matrix4_shearing(const float* values);
t_mat4      matrix4_rotate_x(float  rad);
t_mat4      matrix4_rotate_y(float  rad);
t_mat4      matrix4_rotate_z(float  rad);
t_mat4      matrix4_translate(float tx, float ty, float tz);
t_mat4      matrix4_scaling(float tx, float ty, float tz);


t_mat2      matrix3_submatrix(t_mat3 m, int row, int col);
float       matrix3_minor(t_mat3 m, int row, int col);
float       matrix3_cofactor(t_mat3 m, int row, int col);
float       matrix3_det(t_mat3 m);
#endif   //MATRIX_H

