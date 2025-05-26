#ifndef WORLD_H
#define WORLD_H

#include "matrix.h"
#include "../lib/minift/include/minift.h"

typedef struct s_cam
{
    int         rotate;
    float       fov;
    float       distance;
    t_mat4      to_world;
    t_point4    origin;
    t_vec4      forward;
    t_vec4      up;
    t_vec4      right;
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
    bool            move;
}   t_light;


typedef struct s_world
{
    t_ambient_light a_light;
    t_light         light_src;
    t_cam           cam;
    t_da            objects;
} t_world;


/*Return the matrix to transform the direction of a ray originated from
    a camera to the world*/
t_mat4      camera_to_world(t_cam* cam);
void        camera_setup(t_cam* c);
void        world_setup(t_world* world);


void    print_world(t_world *world);
#endif
