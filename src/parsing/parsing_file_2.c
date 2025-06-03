#include "parsing.h"

bool    parse_sphere(char *line, t_world *world)
{
    t_object sphere;

    ft_bzero(&sphere, sizeof(t_object));
    sphere.hit = sphere_hit;
    sphere.normal_get = sphere_normal;
    sphere.map = sphere_map;
    if (!skip_space_and_check(&line, ERR SPHERE))
        return (false);
    if (!parse_vector_or_point(&line, &sphere.point, 1.f, ERR SPHERE CENTER))
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
    if (!parse_texture(&line, &sphere, ERR SPHERE))
        return (false);
    sphere.r2 = sphere.radius * sphere.radius;
    return (da_append(&world->objects, &sphere));
}

bool    parse_cylinder_two(char *line, t_world *world, t_object* cy)
{
    if (!is_valid_float(line))
        return (printf(ERR CYLINDER INV_FLOAT), false);
    line = ft_strtof(line, &cy->radius);
    cy->radius *= 0.5;
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    if (!is_valid_float(line))
        return (printf(ERR CYLINDER INV_FLOAT), false);
    line = ft_strtof(line, &cy->half_height);
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    cy->half_height *= 0.5;
    if (!parse_rgb(&line, &cy->color))
        return (printf(ERR CYLINDER RGB_ERR), false);
    if (!parse_texture(&line, cy, ERR CYLINDER))
        return (false);
    cy->r2 = cy->radius * cy->radius;
    return (cylinder_add_to_objects(cy, world));
}

bool    parse_cylinder(char *line, t_world *world)
{
    t_object    cylinder;

    ft_bzero(&cylinder, sizeof(t_object));
    cylinder.hit = cylinder_hit;
    cylinder.normal_get = cylinder_normal;
    cylinder.map = cylinder_map;
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    if (!parse_vector_or_point(&line, &cylinder.point, 1.f, ERR CYLINDER CENTER))
        return (false);
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    if (!parse_vector_or_point(&line, &cylinder.axis, 0.f, ERR CYLINDER))
        return (false);
    cylinder.axis = vector_normalize(cylinder.axis);
    if (!skip_space_and_check(&line, ERR CYLINDER))
        return (false);
    return (parse_cylinder_two(line, world, &cylinder));
}

bool    parse_plane(char *line, t_world *world)
{
    t_object    plane;

    ft_bzero(&plane, sizeof(t_object));
    plane.hit = plane_hit;
    plane.normal_get = plane_normal;
    plane.map = plane_map;
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
    if (!parse_texture(&line, &plane, ERR PLANE))
        return (false);
    return (da_append(&world->objects, &plane));
}
