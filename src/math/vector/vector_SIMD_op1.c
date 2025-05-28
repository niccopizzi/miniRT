#include "vectors.h"

inline t_vec4    vector_negate(t_vec4 vector)
{
    return (vector * -1);
}

inline  float   vector_dot_product(t_vec4 vector1, t_vec4 vector2)
{
    return (_mm_cvtss_f32(_mm_dp_ps(vector1, vector2, 0xF1)));
}

inline float   vector_len_squared(t_vec4 vector)
{
    return (vector_dot_product(vector, vector));
}

inline float   vector_len(t_vec4 vector)
{
    return (sqrt(vector_dot_product(vector, vector)));
}

inline t_point4      vector_at(t_point4 origin, t_vec4 direction, float t)
{
    return (_mm_add_ps(origin, direction * t));
}
