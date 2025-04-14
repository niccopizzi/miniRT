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


typedef union u_material
{
    t_vec4      values;
    struct s_elements
    {
        float   ambient;
        float   diffuse;
        float   specular;
        float   shininess;
    } elem;
    
}   t_material;

typedef struct s_primitive
{
    t_object*       object;
    t_material     material;
}   t_primitive;




t_material      material_set(float ambient, float diffuse, float specular, float shininess);
t_object        sphere_new(t_point4 center, float radius);
t_vec4          sphere_normal_at(t_object *sphere, t_point4 *p);
bool            sphere_hit_test(t_ray *ray, t_object *sphere, float* t);
void            sphere_set_transform(t_object *sphere, t_mat4 tm);
#endif  //OBJECTS_H