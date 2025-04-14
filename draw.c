void    draw_routine(t_image *img, t_primitive *obj, t_light *l)
{
    static float    half = WALL_SIZE * 0.5;
    static float    pixel_size = (float)WALL_SIZE / WIDTH;
    t_ray           eye_ray;
    t_ray           ray;
    t_color         color;
    float           intersections[2];
    float           world_y;
    float           world_x;
    float           t;
    
    
    ray.origin = (t_vec4){0,0,-5,1};
    for (int y = 0; y < HEIGHT; y ++)
    {
        world_y = half - pixel_size * y;   
        for (int x = 0; x <  WIDTH; x++)
        {
            world_x = - half + pixel_size * x;
            ray.direction = (t_vec4){world_x, world_y, 10, 1} - ray.origin;
            ray.direction = vector_normalize(ray.direction);
            if (sphere_hit_test(&ray, obj->object, intersections))
            {
                t = fmin(intersections[0], intersections[1]);
                if (t >= 0)
                {
                    t_point4    p = ray_at(ray, t);
                    t_vec4      normal = sphere_normal_at(obj->object, &p);
                    eye_ray.origin = p;
                    eye_ray.direction = -ray.direction;
                    color = phong_lightning(obj, l, &eye_ray, &normal);
                    color = (t_vec4){clamp(color[0], 0, 1), clamp(color[1], 0, 1), clamp(color[2], 0, 1), 0};
                    image_pixel_put(img, x, y, convert_to_rgb(&color));
                }
            }
        }
    }  
}
