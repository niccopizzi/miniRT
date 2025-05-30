#include "material.h"

t_material  material_get_plastic(void)
{
    t_material  plastic;

    plastic = (t_vec4){0.6, 0.7, 0.9, 200.0};
    return (plastic);
}