#ifndef RENDER_H
#define RENDER_H

#include "mlx_utils.h"
#include "objects.h"
#include <time.h>
#include <stdlib.h>

#define MAX_DEPTH 5
#define BIAS (float)1e-3


typedef struct s_phong
{
    t_color effective;
    t_color ambient;
    t_color diffuse;
    t_color specular;
    t_vec4  reflected_ray;
    t_vec4  light_vector;
    float   ldn; //light - normal dot product
    float   rdd; //reflected ray - direction dot product   
    float   factor; //the phong factor for shininess 
}   t_phong;

typedef struct s_shading
{
    double      t;
    float       distance;
    t_point4    hit_point;
    t_vec4      normal_at;
    t_vec4      light_dir;
    t_object*   obj_hit;

} t_shading;


void        render_scene(t_ptrs* ptrs, t_world* world);

t_color     ray_trace(const t_ray *ray, const t_world* world, int depth);
t_color     phong_lightning(const t_object *obj, const t_light* light, 
                            const t_ray* eye_ray, t_vec4 normal);

void        get_shading_info(t_shading* shade_info, const t_ray* ray,
                                const t_light* l);


//Random functions
void    create_seed(void);

#endif // RENDER.H