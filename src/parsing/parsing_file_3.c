#include "parsing.h"

bool    parse_cone_two(char* line, t_world* world, t_object* co)
{
    if (!is_valid_float(line))
        return (printf(ERR CONE INV_FLOAT), false);
    line = ft_strtof(line, &co->radius);
    co->radius *= 0.5;
    if (!skip_space_and_check(&line, ERR CONE))
        return (false);
    if (!is_valid_float(line))
        return (printf(ERR  CONE INV_FLOAT), false);
    line = ft_strtof(line, &co->half_height);
    co->k = co->radius / (co->half_height);
    if (!skip_space_and_check(&line, ERR CONE))
        return (false);
    if (!parse_rgb(&line, &co->color))
        return (printf(ERR CONE RGB_ERR), false);
    if (!parse_texture(&line, co, ERR CONE))
        return (false);
    co->r2 = co->radius * co->radius;
    return (cone_add_to_objects(co, world));
}

bool    parse_cone(char* line, t_world* world)
{
    t_object    cone;

    ft_bzero(&cone, sizeof(t_object));
    cone.hit = cone_hit;
    cone.normal_get = cone_normal;
    cone.map = cylinder_map;
    if (!skip_space_and_check(&line, ERR CONE))
        return (false);
    if (!parse_vector_or_point(&line, &cone.point, 1.f, ERR CONE CENTER))
        return (false);
    if (!skip_space_and_check(&line, ERR CONE))
        return (false);
    if (!parse_vector_or_point(&line, &cone.axis, 0.f, ERR CONE))
        return (false);
    cone.axis = vector_normalize(cone.axis);
    if (!skip_space_and_check(&line, ERR CONE))
        return (false);
    return (parse_cone_two(line, world, &cone));
}