#ifndef OBJECTS_H
#define OBJECTS_H

#include "matrix.h"
#include "ray.h"
#include "../lib/minift/include/minift.h"

typedef enum e_type
{
    SP,
    PL,
    CY,
}   t_type;


//Struct used to store the values of the ray-sphere interesection equation
typedef struct s_sphere_val
{
    double a;
    double b;
    double c;
    double discr;
    double dis_root;
    double denom;
}   t_sphere_val;

#define OBJECT_BYTES 160

typedef struct s_object
{
    //t_type      type; -> Replace type with a pointer to the routine that check if the 
    //                            object was hit, possible signature would be bool hit(t_object *obj, t_ray *, double* t_min), 
    //                              skip the need to check with if statemetns 
    float       radius;
    float       height;
    t_point4    point;
    t_vec4      normal;
    t_point4    center;
    t_vec4      axis;
    t_color     color;
}   t_object;


bool    plane_hit(t_object* pl, t_ray* r, double* t_min);
bool    sphere_hit(t_object* sp, t_ray* r, double* t_min);
#endif  //OBJECTS_H