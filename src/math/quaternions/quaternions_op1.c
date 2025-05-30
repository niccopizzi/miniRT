#include "quaternions.h"

t_quaternion  quaternion_create_re(float w)
{
    t_quaternion    q;

    q.w = w;
    q.x = 0;
    q.y = 0;
    q.z = 0;

    return (q);
}
t_quaternion  quaternion_create_img(float w, float x, float y, float z)
{
    t_quaternion    q;

    q.w = w;
    q.x = x;
    q.y = y;
    q.z = z;

    return (q);
}

t_quaternion  quaternion_set_angle(t_vec4 axis, float radians)
{
    t_quaternion    q;

    q.w = cosf(radians * 0.5);
    axis *= sinf(radians * 0.5);
    q.x = axis[0];
    q.y = axis[1];
    q.z = axis[2];
    return (q);
}
t_quaternion  quaternion_multiply(t_quaternion* q1, t_quaternion* q2)
{
    t_quaternion    q3;

    q3.w =  q1->w * q2->w - q1->x * q2->x - q1->y * q2->y - q1->z * q2->z;
    q3.x =  q1->w * q2->x + q1->x * q2->w + q1->y * q2->z - q1->z * q2->y;
    q3.y =  q1->w * q2->y - q1->x * q2->z + q1->y * q2->w + q1->z * q2->x;
    q3.z =  q1->w * q2->z + q1->x * q2->y - q1->y * q2->x + q1->z * q2->w;

    return (q3);
}

t_mat4          quaternion_to_mat4(t_quaternion* q)
{
    t_mat4  m;

    m.row[0] = (t_vec4){ 1 - 2 * (q->y * q->y + q->z * q->z),
                            2 * (q->x * q->y + q->z * q->w),
                            2 * (q->z * q->x - q->y * q->w), 0};
    m.row[1] = (t_vec4){ 2 * (q->x * q->y - q->z * q->w), 
                            1 - 2 * (q->z * q->z + q->x * q->x),
                            2 * (q->y * q->z + q->x * q->w), 0};
    m.row[2] = (t_vec4){ 2 * (q->z * q->x + q->y * q->w),
                            2 * (q->y * q->z - q->x * q->w),
                            1 - 2 * (q->y * q->y + q->x * q->x), 0};
    m.row[3] = (t_vec4){0, 0, 0, 1};

    return (m);
}