#include "matrix.h"

t_mat4 matrix4_view_transform(t_point4 from, t_vec4 forward, t_vec4 up)
{
    t_mat4  m;

    m.row[0] = vector_cross_prod(forward, up);
    m.row[1] = vector_cross_prod(m.row[0], forward);
    m.row[2] = -forward;
    m.row[3] = (t_vec4){0, 0, 0, 1};
    return (matrix4_mult_mat4(m, 
            matrix4_translate(-forward[0], -forward[1], -forward[2])));
}

t_mat4 matrix4_scaling(float tx, float ty, float tz)
{
    t_mat4  m;

    m = matrix4_identity();
    m.row[0][0] = tx;
    m.row[1][1] = ty;
    m.row[2][2] = tz;

    return (m);
}