#ifndef RENDER_H
#define RENDER_H

#include "mlx_utils.h"
#include "objects.h"

void    render_scene(t_ptrs* ptrs, t_world* world);
void    camera_setup(t_cam* c);

/*Return a ray translated into world coordinate*/
t_vec4  camera_to_world(float x, float y, t_cam* cam);
#endif // RENDER.H