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


typedef struct s_object
{
    t_type      type;
    float       radius;
    float       height;
    t_point4    point;
    t_vec4      normal;
    t_point4    center;
    t_vec4      axis;
    t_color     color;
    t_mat4      transform;
}   t_object;

#endif  //OBJECTS_H