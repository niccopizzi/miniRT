#ifndef OBJECTS_H
#define OBJECTS_H

#include "ray.h"
#include "material.h"
#include "../lib/minift/include/minift.h"

//Forward declaration
typedef struct s_shading    t_shading;
typedef struct s_object     t_object;
typedef struct s_world      t_world;

struct s_object
{
    bool            (*hit)(const t_object*, const t_ray*, double* t_min);
    t_vec4          (*normal_get)(const t_object*, t_shading* info);
    float           radius;
    float           half_height;
    t_material      material;
    t_point4        point;
    t_vec4          normal;
    t_point4        center;
    t_vec4          axis;
    t_color         color;
    t_object*       father;
};

//Struct used to store the values of the ray-sphere intersection equation
typedef struct s_sp_equation
{
    double a;
    double b;
    double c;
    double discr;
    double denom;
    double t;
}   t_sp_equation;

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
bool    plane_hit(const t_object* pl, const t_ray* r, double* t_min);
bool    sphere_hit(const t_object* sp, const t_ray* r, double* t_min);
bool    cylinder_hit(const t_object* cy, const t_ray* r, double *t_min);
bool    disk_hit(const t_object* ds, const t_ray* r, double* t_min);


t_vec4  sphere_normal(const t_object* obj, t_shading* info);
t_vec4  plane_normal(const t_object* obj, t_shading* info);
t_vec4  cylinder_normal(const t_object* obj, t_shading* info);


bool    check_t(double t, double *t_min);
bool    is_inside_cap(const t_point4 ray_at, const t_object* cy);
bool    cylinder_add_to_objects(t_object* cy, t_world* world);
#endif  //OBJECTS_H