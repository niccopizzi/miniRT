#ifndef MATERIAL_H
#define MATERIAL_H

#include "vectors.h"

typedef t_vec4  t_material;

#define AMBIENT     0
#define DIFFUSE     1
#define SPECULAR    2
#define SHININESS   3

t_material  material_get_plastic(void);

#endif