#ifndef WORLD_H
#define WORLD_H

#include "vectors.h"
#include "../lib/minift/include/minift.h"

typedef struct s_cam
{
    float      fov;
    t_point4   origin;
    t_vec4     forward;
}   t_cam;

typedef struct s_ambient_light
{
    float       ratio;
    t_color     color;
}   t_ambient_light;

typedef struct s_light
{
    float           brightness;
    t_color         color;
    t_point4        pos;
}   t_light;


typedef struct s_world
{
    t_ambient_light a_light;
    t_light         light_src;
    t_cam           cam;
    t_da            objects;
} t_world;


void    print_world(t_world *world);
#endif
