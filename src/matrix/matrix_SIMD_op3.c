#include "matrix.h"

t_transform      matrix4_shearing(const float* values)
{
    t_transform  m;

    m.t.row[0] = (t_vec4){1, values[0], values[1], 0};
    m.t.row[1] = (t_vec4){values[2], 1, values[3], 0};
    m.t.row[2] = (t_vec4){values[4], values[5], 1, 0};
    m.t.row[3] = (t_vec4){0, 0, 0, 1};

    m.inv = matrix4_invert(m.t);
    return (m);
}

t_transform      matrix4_translate(float tx, float ty, float tz)
{
    t_transform  m;

    m.t = matrix4_identity();
    m.t.row[0][3] = tx;
    m.t.row[1][3] = ty;
    m.t.row[2][3] = tz;

    m.inv = matrix4_invert(m.t);
    return (m);
}


t_transform      matrix4_rotate_x(float  rad)
{
    t_transform  m;
    float   sinr;
    float   cosr;

    m.t = matrix4_identity();
    sinr = sinf(rad);
    cosr = cosf(rad);
    m.t.row[1] = (t_vec4){0, cosr, -sinr, 0};
    m.t.row[2] = (t_vec4){0, sinr, cosr, 0};

    m.inv = matrix4_invert(m.t);
    return (m);
}

t_transform      matrix4_rotate_y(float rad)
{
    t_transform  m;
    float        sinr;
    float        cosr;

    m.t = matrix4_identity();
    sinr = sinf(rad);
    cosr = cosf(rad);
    m.t.row[0] = (t_vec4){cosr, 0, sinr, 0};
    m.t.row[2] = (t_vec4){-sinr, 0, cosr, 0};

    m.inv = matrix4_invert(m.t);
    return (m);
}

t_transform     matrix4_rotate_z(float rad)
{
    t_transform  m;
    float        sinr;
    float        cosr;

    m.t = matrix4_identity();
    sinr = sinf(rad);
    cosr = cosf(rad);
    m.t.row[0] = (t_vec4){cosr, -sinr, 0, 0};
    m.t.row[1] = (t_vec4){sinr, cosr, 0, 0};

    m.inv = matrix4_invert(m.t);
    return (m);
}