#ifndef RENDER_H
#define RENDER_H

#include "mlx_utils.h"
#include "objects.h"
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#define MAX_DEPTH 5
#define SAMPLE_SIZE 20
#define BIAS (float)0.0001

typedef struct s_shading
{
    bool                front_face;
    float               t;
    float               distance;
    t_point4            hit_point;
    t_vec4              normal_at;
    t_vec4              light_dir;
    t_color             ambient;
    const t_ray*        hitting_ray;
    t_object*           obj_hit;

} t_shading;


void        render_scene(t_ptrs* ptrs, t_world* world);
t_color     ray_trace(const t_ray *ray, const t_world* world, int depth);
void        get_shading_info(t_shading* shade_info, const t_ray* ray,
                                const t_world* world);
t_color     color_at_hit(t_shading* info, const t_light* l);
t_color     calculate_color(int x, int y, const t_world* world, t_ray* r);
t_color     sample_pixel(int x, int y, const t_world* world, t_ray* r);

//Random functions
void    create_seed(void);
float   generate_random_x(int x, float scale);
float   generate_random_y(int y, float scale);
#endif // RENDER.H