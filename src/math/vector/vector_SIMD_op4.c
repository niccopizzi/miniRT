#include "vectors.h"

inline t_vec4  vector_reflect(const t_vec4 to_reflect, const t_vec4 normal)
{
    return (to_reflect - (normal * 2 * vector_dot_product(to_reflect, normal)));
}