#include "matrix.h"

t_mat4      matrix4_shearing(const float* values)
{
    t_mat4  m;

    m.row[0] = (t_vec4){1, values[0], values[1], 0};
    m.row[1] = (t_vec4){values[2], 1, values[3], 0};
    m.row[2] = (t_vec4){values[4], values[5], 1, 0};
    m.row[3] = (t_vec4){0, 0, 0, 1};

    return (m);
}

t_mat4      matrix4_translate(float tx, float ty, float tz)
{
    t_mat4  m;

    m = matrix4_identity();
    m.row[0][3] = tx;
    m.row[1][3] = ty;
    m.row[2][3] = tz;

    return (m);
}


t_mat4      matrix4_rotate_x(float  rad)
{
    t_mat4  m;
    float   sinr;
    float   cosr;

    m = matrix4_identity();
    sinr = sinf(rad);
    cosr = cosf(rad);
    m.row[1] = (t_vec4){0, cosr, -sinr, 0};
    m.row[2] = (t_vec4){0, sinr, cosr, 0};

    return (m);
}

t_mat4      matrix4_rotate_y(float rad)
{
    t_mat4  m;
    float   sinr;
    float   cosr;

    m = matrix4_identity();
    sinr = sinf(rad);
    cosr = cosf(rad);
    m.row[0] = (t_vec4){cosr, 0, sinr, 0};
    m.row[2] = (t_vec4){-sinr, 0, cosr, 0};

    return (m);
}

t_mat4     matrix4_rotate_z(float rad)
{
    t_mat4  m;
    float   sinr;
    float   cosr;

    m = matrix4_identity();
    sinr = sinf(rad);
    cosr = cosf(rad);
    m.row[0] = (t_vec4){cosr, -sinr, 0, 0};
    m.row[1] = (t_vec4){sinr, cosr, 0, 0};

    return (m);
}