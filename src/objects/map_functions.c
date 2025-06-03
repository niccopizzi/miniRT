#include "objects.h"

void    sphere_map(const t_object* obj, const t_point4 p, float* u, float* v)
{
    float       theta;
    float       phi;
    t_point4    real_p;

    real_p = p - obj->point;
    theta = atan2(real_p[2], real_p[0]);
    phi = asin(real_p[1] / obj->radius);
    *u = (theta + PI) / (PI * 2);
    *v = phi / PI + 0.5;
}

void    plane_map(const t_object* obj, const t_point4 p, float* u, float* v)
{
    
    (void)obj;
    *u = p[0] - (int)p[0];
    *v = p[1] - (int)p[1];
}

void    cylinder_map(const t_object* obj, const t_point4 p, float* u, float* v)
{
    float       theta;
    t_point4    real_p;

    real_p = (p - obj->point);
    theta = atan2(real_p[0], real_p[2]);
    *u = (theta + PI) / (PI * 2);
    *v = (real_p[1] + obj->half_height) / obj->half_height * 2;
}