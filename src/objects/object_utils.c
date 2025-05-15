#include "objects.h"

void   object_material_setup(t_object* obj)
{
    obj->material[SHININESS] = 200.0;
    obj->material[AMBIENT] = 0.1;
    obj->material[DIFFUSE] = 0.9;
    obj->material[SPECULAR] = 0.9;
}