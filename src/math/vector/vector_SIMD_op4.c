#include "vectors.h"

inline t_vec4  vector_reflect(const t_vec4 to_reflect, const t_vec4 normal)
{
    return (to_reflect - (normal * 2 * vector_dot_product(to_reflect, normal)));
}

t_vec4    vector_clamp(t_vec4 v, float min, float max)
{
    size_t  index;

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