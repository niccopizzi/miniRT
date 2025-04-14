#ifndef VECTORS_H
# define VECTORS_H

/* typedef struct s_vec3
{
    float x;
    float y;
    float z;
} t_vec3; */

#include <immintrin.h>
#include <emmintrin.h>
#include <x86intrin.h>

typedef     __m128 t_vec4;
typedef     t_vec4  t_point4;
typedef     t_vec4  t_color;

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

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
/* float       vector_len_sqrd(t_vec3 *vector);
float       vector_len(t_vec3 *vector);
float       vector_dot_prod(t_vec3 *vector1, t_vec3 *vector2);


These functions take a pointer to all the operands, including result, and return the address of result
    In this way they can change a vector in place (by passing a pointer to the vector as res) and can be called
    in other functions call
    
t_vec3*     vector_add_vec(t_vec3 *res, t_vec3 *vector1, t_vec3 *vector2);
t_vec3*     vector_add_scalar(t_vec3 *res, t_vec3 *vector, float scalar);
t_vec3*     vector_sub_vec(t_vec3 *res, t_vec3 *vector1, t_vec3 *vector2);
t_vec3*     vector_mult_vec(t_vec3 *res, t_vec3 *vector1, t_vec3 *vector2);
t_vec3*     vector_mult_scalar(t_vec3 *res, t_vec3 *vector, float scalar);
t_vec3*     vector_cross_prod(t_vec3 *res, t_vec3 *vector1, t_vec3 *vector2);
t_vec3*     vector_translate(t_vec3 *res, t_vec3 *vector, t_vec3 *translation);
t_vec3*     vector_div_scalar(t_vec3 *res, t_vec3 *vector, float scalar);
t_vec3*     vector_negate(t_vec3 *res, t_vec3 *vector);
t_vec3*     vector_normalize(t_vec3 *res, t_vec3 *vector);
t_point3*   vector_at(t_point3 *at, t_point3 *origin, t_vec3 *direction, float a);


 */
#endif