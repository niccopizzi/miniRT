#include "parsing.h"
#include "miniRT.h"

bool    parse_ambient_light(char *line, t_world *world)
{
    float   ratio;
    t_vec4  color;

    if (!skip_space_and_check(&line, ERR A_LIGHT))
        return (false);
    if (!is_valid_float(line))
        return (printf(ERR A_LIGHT RATIO INV_FLOAT), false);
    line = ft_strtof(line, &ratio);
    if (ratio < 0.0f || ratio > 1.0f)
        return (printf(ERR A_LIGHT RATIO OOR), false);
    if (!skip_space_and_check(&line, ERR A_LIGHT))
        return (false);
    if (!parse_rgb(&line, &color))
        return (printf(ERR A_LIGHT RGB_ERR), false);
    if (*line != '\n')
        return (printf(ERR A_LIGHT ENDLINE_ERR), false);
    world->ambient = color * ratio;
    return (true);
}

bool    parse_camera(char *line, t_world *world)
{
    t_cam   c;

    if (!skip_space_and_check(&line, ERR CAM))
        return (false);
    if (!parse_vector_or_point(&line, &c.origin, 1.f, ERR CAM COOR))
        return (false);
    if (!skip_space_and_check(&line, ERR CAM))
        return (false);
    if (!parse_vector_or_point(&line, &c.forward, 0.f, ERR CAM COOR))
        return (false);
    c.forward = vector_normalize(c.forward);
    if (!skip_space_and_check(&line, ERR CAM))
        return (false);
    c.fov = ft_atoi(line);
    if (c.fov <= 0 || c.fov > 180)
        return (printf(ERR CAM FOV OOR), false);
    while (*line >= '0' && *line <= '9')
        line++;
    if (*line != '\n')
        return (printf(ERR CAM ENDLINE_ERR), false);
    c.rotate = false;
    world->cam = c;
    return (true);
}

bool    parse_light(char *line, t_world *world)
{
    t_light l;

    if (!skip_space_and_check(&line, ERR LIGHT))
        return (false);
    if (!parse_vector_or_point(&line, &l.pos, 1.f, ERR LIGHT COOR))
        return (false);
    if (!skip_space_and_check(&line, ERR LIGHT))
        return (false);
    if (!is_valid_float(line))
        return (printf(ERR LIGHT RATIO INV_FLOAT), false);
    line = ft_strtof(line, &l.brightness);
    if (l.brightness < 0 || l.brightness > 1)
        return (printf(ERR LIGHT RATIO OOR), false);
    if (BONUS && !skip_space_and_check(&line, ERR LIGHT))
        return (false);
    if (BONUS && !parse_rgb(&line, &l.color))
        return (printf(ERR LIGHT RGB_ERR), false);
    if (*line != '\n')
        return (printf(ERR LIGHT ENDLINE_ERR), false);
    l.effective = l.brightness * l.color;
    l.move = false;
    world->lights = l;
    return (true);
}

bool    parse_on_identifier(char* trim, t_world* world, int* declared)
{
    if (trim[0] == 'A' && trim[1] == ' ')
    {
        if (declared[0])
            return (printf(ERR A_LIGHT MULT), false);
        declared[0] ++;
        return(parse_ambient_light(trim + 1, world));
    }
    else if (trim[0] == 'C' && trim[1] == ' ')
    {
        if (declared[1])
            return (printf(ERR CAM MULT), false);
        declared[1] ++;
        return(parse_camera(trim + 1, world));
    }
    else if (trim[0] == 'L' && trim[1] == ' ')
        return (parse_light(trim + 1, world));
    else if (trim[0] == 's' && trim[1] == 'p' && trim[2] == ' ')
        return (parse_sphere(trim + 2, world));
    else if (trim[0] == 'p' && trim[1] == 'l' && trim[2] == ' ')
        return (parse_plane(trim + 2, world));
    else if (trim[0] == 'c' && trim[1] == 'y' && trim[2] == ' ')
        return (parse_cylinder(trim + 2, world));
    else if (trim[0] != '\n')
        return (printf(ERR UNKOWN_INPUT), false);
    return (true);
}

bool    parse_file(int fd, t_world *world)
{
    char    *line;
    char    *trim;
    int     declared[2];
    bool    valid;

    valid = true;
    declared[0] = 0;
    declared[1] = 0;
    while(valid && get_next_line(fd, &line))
    {
        trim = ft_strtrim(line, " \t");
        valid = parse_on_identifier(trim, world, declared);
        free(line), 
        free(trim), 
        line = NULL, 
        trim = NULL;
    }
    return (valid);
}
