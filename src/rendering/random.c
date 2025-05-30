#include "render.h"

void    create_seed(void)
{
    unsigned short  seed[3];
    
    srand(time(NULL));
    seed[0] = (unsigned short)(rand() & 0xFFFF);
    seed[1] = (unsigned short)(rand() & 0xFFFF);
    seed[2] = (unsigned short)(rand() & 0xFFFF);

    seed48(seed);
}

inline float   generate_random_x(int x, float scale)
{
    return ((2 * ((x + (drand48() - 0.5)) / WIDTH) - 1) * scale * IMG_RATIO);
}

inline float    generate_random_y(int y, float scale)
{
    return((1 - 2 * ((y + (drand48() - 0.5)) / HEIGHT)) * scale);
}

t_color    sample_pixel(int x, int y, const t_world* world, t_ray* r)
{
    int         i;
    float       scale;
    t_color     sampled_color;
    t_point4    world_point;

    i = 0;
    sampled_color = vector_from_float(0.0f);
    scale = world->cam.scale;
    while (i < SAMPLE_SIZE)
    {
        world_point = matrix4_mult_vec4(&world->cam.to_world, (t_vec4)
                        {(2 * ((x + (drand48() - 0.5)) / WIDTH) - 1) 
                            * scale * IMG_RATIO, 
                        (1 - 2 * ((y + (drand48() - 0.5)) / HEIGHT)) 
                            * scale, -1, 1});
        r->direction = vector_normalize(world_point - r->origin);
        sampled_color += ray_trace(r, world, 0);
        i++;
    }
    return (sampled_color / (float)SAMPLE_SIZE);
}