#ifndef RENDER_H
#define RENDER_H

#include "mlx_utils.h"
#include "objects.h"

#define MAX_DEPTH 5
#define BIAS (float)1e-3

typedef struct s_brdf
{
    t_vec4      normal;

}   t_brdf;


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

void        render_scene(t_ptrs* ptrs, t_world* world);

t_color     ray_trace(const t_ray *ray, const t_world* world, int depth);
t_color     phong_lightning(const t_object *obj, const t_light* light, 
                            const t_ray* eye_ray, t_vec4 normal);


#endif // RENDER.H