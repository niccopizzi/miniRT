#include "matrix.h"

t_mat4  matrix4_rodrigues_rot(t_vec4 axis, double angle)
{
    t_mat4  r;
    float   st;
    float   ct;
    float   x;
    float   y;
    float   z;

    st = sin(angle);
    ct = cos(angle);
    x = axis[0];
    y = axis[1];
    z = axis[2];
    r.row[0] = (t_vec4){ct + x * x * (1 - ct),  x * y * (1 - ct) - z * st,
                        x * z * (1 - ct) + y * st, 0};
    r.row[1] = (t_vec4){y * x * (1 - ct) + z * st, ct + y * y * (1 - ct),
                        y * z * (1 - ct) - x * st, 0};
    r.row[2] = (t_vec4){z * x * (1 - ct) - y * st, z * y * (1 - ct) + x * st,
                        ct + z * z * (1 - ct), 0};
    r.row[3] = (t_vec4){0, 0, 0, 1};
    return (r);
}

t_mat4  matrix4_scaling(float tx, float ty, float tz)
{
    t_mat4  m;

    m = matrix4_identity();
    m.row[0][0] = tx;
    m.row[1][1] = ty;
    m.row[2][2] = tz;

    return (m);
}