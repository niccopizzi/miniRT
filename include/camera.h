#ifndef CAMERA_H
#define CAMERA_H

#include "vectors.h"
#include "ray.h"

typedef struct s_cam
{
    float       hsize;
    float       vsize;
    float       fov;
    t_point4    origin;
    t_vec4      forward;
    t_mat4      transform;
}   t_cam;

void        camera_setup(t_cam *camera);

/* void        camera_setup(t_cam *camera);
t_point4    camera_pixel_get(int x, int y, float zoom);
t_ray       camera_ray_get(t_cam *camera, t_point3 *camera_pixel);
 */
#endif //CAMERA_H