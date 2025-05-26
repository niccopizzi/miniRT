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
    bool                (*hit)(const struct s_object*, const t_ray*, double* t_min);
     /*Hit function to call when checking for intersections between the ray and the object*/
    t_vec4              (*normal_get)(const struct s_object*, const t_ray*, float time);
    /*The function that returns the normal of the object at a given point*/
    float               radius;
    float               half_height;
    t_vec4              material;
    t_point4            point;
    t_vec4              normal;
    t_point4            center;
    t_vec4              axis;
    t_color             color;
    struct s_object*    father;
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

typedef struct s_cy_equation
{
    double  a;
    double  b;
    double  c;
    double  discr;
    double  dv;
    double  xv;

} t_cy_equation;


/*Hit routines for the different objects, they are passed to the object struct
    so they can be called directly from the ray_trace function without having
    to check what object we need to test for intersection*/


void    object_material_setup(t_object* obj);
bool    plane_hit(const t_object* pl, const t_ray* r, double* t_min);
bool    sphere_hit(const t_object* sp, const t_ray* r, double* t_min);
bool    cylinder_hit(const t_object* cy, const t_ray* r, double *t_min);
bool    disk_hit(const t_object* ds, const t_ray* r, double* t_min);


t_vec4  sphere_normal(const t_object* obj, const t_ray* r, float time);
t_vec4  plane_normal(const t_object* obj, const t_ray* r, float time);
t_vec4  cylinder_normal(const t_object* obj, const t_ray* r, float time);


bool    check_t(double t, double *t_min);
bool    is_inside_cap(const t_point4 ray_at, const t_object* cy);
bool    cylinder_add_to_objects(t_object* cy, t_world* world);
#endif  //OBJECTS_H