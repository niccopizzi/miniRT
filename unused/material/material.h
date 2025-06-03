#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"

typedef struct s_shading t_shading;

typedef struct s_material
{
    t_ray  (*bounce_ray)(const t_ray* r, const t_shading* info);
    float   refraction_index;

} t_material;

#define AMBIENT     0
#define DIFFUSE     1
#define SPECULAR    2
#define SHININESS   3

t_material  material_get_diffuse(void);

#endif