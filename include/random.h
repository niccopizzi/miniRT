#ifndef RANDOM_H
#define RANDOM_H

#include "ray.h"
#include "mlx_utils.h"


#define SAMPLE_SIZE 20

typedef struct s_world t_world;

void        create_seed(void);
float       generate_random_x(int x, float scale);
float       generate_random_y(int y, float scale);
t_vec4      random_unit_vector(float min, float max);
t_color     sample_pixel(int x, int y, const t_world* world, t_ray* r);

#endif