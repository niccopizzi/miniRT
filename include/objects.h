#ifndef OBJECTS_H
#define OBJECTS_H

#include "ray.h"
#include "../lib/minift/include/minift.h"

#define SHININESS   0
#define AMBIENT     1
#define DIFFUSE     2
#define SPECULAR    3

typedef enum e_type
{
    SP,
    PL,
    CY,
}   t_type;

typedef struct s_object
{
    bool        (*hit)(struct s_object*, t_ray*, double* t_min); /*Hit function to call when checking for intersections
                                                            between the ray and the object*/
    t_vec4      (*norm)(struct s_object*, t_ray, float time);
    float       radius;
    float       height;
    t_vec4      material;
    t_point4    point;
    t_vec4      normal;
    t_point4    center;
    t_point4    bp;
    t_vec4      axis;
    t_color     color;
}   t_object;

//Struct used to store the values of the ray-sphere intersection equation
typedef struct s_sphere_val
{
    double a;
    double b;
    double c;
    double discr;
    double denom;
    double t;
}   t_sp_val;

//Struct used to store the values of the ray-cylinder intersection equation

typedef struct s_cylinder_val
{
    t_vec4      ba; 
    t_vec4      oc; 
    double      baba; 
    double      bard; 
    double      baoc; 
    double      k2; 
    double      k1; 
    double      k0; 
    double      h;
    double      t;
    double      y; 
} t_cy_val;

typedef struct s_inf_cy_val
{
    double      card;
    double      caoc;
    double      a;
    double      b;
    double      c;
    double      h;
    double      t;
}   t_inf_cy_val;


/*Hit routines for the different objects, they are passed to the object struct
    so they can be called directly from the ray_trace function without having
    to check what object we need to test for intersection*/


void    object_material_setup(t_object* obj);
bool    plane_hit(t_object* pl, t_ray* r, double* t_min);
bool    sphere_hit(t_object* sp, t_ray* r, double* t_min);
bool    cylinder_hit(t_object* cy, t_ray* r, double *t_min);


t_vec4  sphere_normal(t_object* obj, t_ray r, float time);
t_vec4  plane_normal(t_object* obj, t_ray r, float time);
//t_vec4  
#endif  //OBJECTS_H