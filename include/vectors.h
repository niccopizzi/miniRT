#ifndef VECTORS_H
# define VECTORS_H

#include <immintrin.h>
#include <emmintrin.h>
#include <x86intrin.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef     __m128 t_vec4;

typedef     t_vec4  t_point4;
typedef     t_vec4  t_color;
 

#define PI          3.141593
#define EPSILON     0.000001

t_vec4      vector_negate(t_vec4 vector);
float       vector_dot_product(t_vec4 vector1, t_vec4 vector2);
float       vector_len_squared(t_vec4 vector);
float       vector_len(t_vec4 vector);
t_point4    vector_at(t_point4 origin, t_vec4 direction, float t);
t_vec4      vector_normalize(t_vec4 vector);
t_vec4      vector_cross_prod(t_vec4 vector1, t_vec4 vector2);

bool        vector_in_range(t_vec4 vector, float min, float max);
bool        vector_compare_eq(t_vec4 vector1, t_vec4 vector2);
bool        vector_compare_lt(t_vec4 vector1, t_vec4 vector2);
bool        vector_compare_gt(t_vec4 vector1,  t_vec4 vector2);

t_vec4      vector_from_float(float a);
t_vec4      vector_from_array(const float *array);


t_vec4      vector_reflect(const t_vec4 to_reflect, const t_vec4 normal);
t_point4    lerp(t_point4 p1, t_point4 p2, float a);

#endif
