#ifndef LIGHT_H
#define LIGHT_H

#include "mlx_utils.h"
#include "objects.h"

#define EFFECTIVE 0
#define AMBIENT 1
#define DIFFUSE 2
#define SPECULAR 3

void        light_move(t_ptrs *ptrs, int key);
t_color     phong_lightning(const t_object *obj, const t_light* light, 
                            const t_ray* eye_ray, const t_vec4* normal);

#endif //LIGHT_H