#ifndef QUATERNIONS_H
#define QUATERNIONS_H

#include "matrix.h"

typedef struct s_quaternion
{
    float   w;
    float   x;
    float   y;
    float   z;
}   t_quaternion;

t_quaternion  quaternion_create_re(float w);
t_quaternion  quaternion_create_img(float w, float x, float y, float z);
t_quaternion  quaternion_set_angle(t_vec4 axis, float radians);
t_quaternion  quaternion_multiply(t_quaternion* q0, t_quaternion* q1);

t_mat4          quaternion_to_mat4(t_quaternion* q);

#endif //QUATERNIONS_H