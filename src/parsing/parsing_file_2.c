#include "parsing.h"
#include "miniRT.h"

bool    parse_sphere(char *line, t_world *world)
{
    t_object sphere;

    sphere.type = SP;
    if (!skip_space_and_check(&line, ERR SPHERE))
        return (false);
    if (!parse_vector_or_point(&line, &sphere.center, 1.f, ERR SPHERE CENTER))
        return (false);
    if (!skip_space_and_check(&line, ERR SPHERE))
        return (false);
    if (!is_valid_float(line))
        return (printf(ERR SPHERE INV_FLOAT), false);
    line = ft_strtof(line, &sphere.radius);
    sphere.radius *= 0.5;
    if (!skip_space_and_check(&line, ERR SPHERE))
        return (false);
    if (!parse_rgb(&line, &sphere.color))
        return (printf(ERR SPHERE RGB_ERR), false);
    if (*line != '\n')
        return (printf(ERR SPHERE ENDLINE_ERR), false);
    sphere.transform = matrix4_identity();
    return (da_append(&world->objects, &sphere));
}

bool    parse_cylinder_two(char *line, t_world *world, t_object cylinder)
{
    if (!is_valid_float(line))
        return (printf(ERR CYLINDER INV_FLOAT), false);
    line = ft_strtof(line, &cylinder.radius);
    cylinder.radius *= 0.5;
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    if (!is_valid_float(line))
        return (printf(ERR CYLINDER INV_FLOAT), false);
    line = ft_strtof(line, &cylinder.height);
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    if (!parse_rgb(&line, &cylinder.color))
        return (printf(ERR CYLINDER RGB_ERR), false);
    if (*line != '\n')
        return (printf(ERR CYLINDER ENDLINE_ERR), false);
    cylinder.transform = matrix4_identity();
    return (da_append(&world->objects, &cylinder));
}

bool    parse_cylinder(char *line, t_world *world)
{
    t_object    cylinder;

    cylinder.type = CY;
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    if (!parse_vector_or_point(&line, &cylinder.center, 1.f, ERR CYLINDER CENTER))
        return (false);
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    if (!parse_vector_or_point(&line, &cylinder.axis, 0.f, ERR CYLINDER))
        return (false);
    cylinder.axis = vector_normalize(cylinder.axis);
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    return (parse_cylinder_two(line, world, cylinder));
}

bool    parse_plane(char *line, t_world *world)
{
    t_object    plane;

    plane.type = PL;
    if (!skip_space_and_check(&line, ERR PLANE))
        return (false);
    if (!parse_vector_or_point(&line, &plane.point, 1.f, ERR PLANE))
        return (false);
    if (!skip_space_and_check(&line, ERR PLANE))
        return (false);
    if (!parse_vector_or_point(&line, &plane.normal, 0.f, ERR PLANE NORMAL))
        return (false);
    plane.normal = vector_normalize(plane.normal);
    if (!skip_space_and_check(&line, ERR PLANE))
        return (false);
    if (!parse_rgb(&line, &plane.color))
        return (printf(ERR PLANE RGB_ERR), false);
    if (*line != '\n')
        return (printf(ERR PLANE ENDLINE_ERR), false);
    plane.transform = matrix4_identity();
    return (da_append(&world->objects, &plane));
}
