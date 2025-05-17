#ifndef RENDER_H
#define RENDER_H

#include "mlx_utils.h"
#include "objects.h"

typedef struct s_brdf
{
    t_vec4      normal;

}   t_brdf;

#define EFFECTIVE   0

void        render_scene(t_ptrs* ptrs, t_world* world);
void        camera_setup(t_cam* c);

t_color     ray_trace(t_ray *ray, const t_world* world);
t_color     phong_lightning(t_object *obj, const t_light* light, 
                            t_ray* eye_ray, t_vec4 normal);

/*Return a ray translated into world coordinate*/
t_vec4      camera_to_world(float x, float y, t_cam* cam);
#endif // RENDER.H