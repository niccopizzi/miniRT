#include "parsing.h"

bool    is_valid_vector(t_vec4 *vec, float min, float max, char *msg)
{
    if (!vector_in_range(*vec, min, max))
    {
        printf("%s %s", msg, OOR);
        return (false);
    }
    if (vector_compare_eq(*vec, vector_from_float(0.f)))
    {
        printf("%s %s", msg, INV_VECTOR);
        return (false);
    }
    return (true);
}

bool    check_if_declared(int* declared)
{
    if (!declared[0])
        return (printf(ERR A_LIGHT MISS_DECL), false);
    if (!declared[1])
        return (printf(ERR CAM MISS_DECL), false);
    if (!declared[2])
        return (printf(ERR LIGHT MISS_DECL), false);
    return (true);
}