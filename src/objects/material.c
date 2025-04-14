#include "objects.h"

t_material  material_set(float ambient, float diffuse, float specular, float shininess)
{
    t_material  material;

    material.values = (t_vec4){ambient, diffuse, specular, shininess};
    return (material);
}