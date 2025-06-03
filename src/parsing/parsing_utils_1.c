#include "parsing.h"

bool    is_valid_file(char *filename, t_world *world)
{
    char    *str;
    bool    ret;
    int     fd;

    str = ft_strnstr(filename, ".rt", ft_strlen(filename));
    if (!str || ft_strlen(str) != 3)
    {
        printf("Error: %s: file not valid\n", filename);
        return (false);
    }
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Error: %s: %s\n", filename, strerror(errno));
        return (false);
    }
    ret = parse_file(fd, world);
    close(fd);
    return (ret);
}

bool    skip_space_and_check(char **line, char *msg)
{
    if (**line != ' ' && **line != '\t')
    {
        return (printf("%s%s", msg, MISS_SPACE), false);
    }
    while (**line && ft_isspace(**line))
        *line = *line + 1;
    if (!**line)
    {
        return(printf("%s%s", msg, MISS_VAL), false);
    }
    return (true);
}

bool    is_valid_float(char *line)
{
    int i;

    i = 0;
    if (line[0] == '+' || line[0] == '-')
        i++;
    while (line[i] >= '0' && line[i] <= '9')
        i++;
    if (!i || (i == 1 && (line[0] == '-' || line[0] == '+')))
        return (false);
    if (line[i] == '.')
    {
        i++;
        if (line[i] < '0' || line[i] > '9')
            return (false);
    }
    return (true);
}

bool    parse_rgb(char **line, t_color *color)
{
    int     i;
    float   data[4];

    i = 0;
    while ((*line)[i] >= '0' && (*line)[i] <= '9')
        i++;
    if (i > 3 || (*line)[i] != ',')
        return (false);
    data[0] = (float)ft_atoi(*line) / 255;
    i++;
    data[1] = (float)ft_atoi((*line) + i) / 255;
    while ((*line)[i] >= '0' && (*line)[i] <= '9')
        i++;
    if (i > 7 || (*line)[i] != ',')
        return (false);
    i++;
    data[2] = (float)ft_atoi((*line) + i) / 255;
    while ((*line)[i] >= '0' && (*line)[i] <= '9')
        i++;
    if ((*line)[i] && !ft_isspace((*line)[i]))
       return (false);
    data[3] = 0.f;
    *color = _mm_load_ps(data);
    return ((*line) = (*line) + i, vector_in_range(*color, 0, 1));
}

bool    parse_vector_or_point(char **line, t_vec4* value, float point, char *msg)
{
    float   data[4];

    data[3] = point;
    if (!is_valid_float(*line))
        return (printf("%s %s", msg, INV_FLOAT), false);
    *line = ft_strtof(*line, &data[0]);
    if (**line != ',')
        return (printf("%s %s", msg, MISS_SPACE), false);
    *line = *line + 1;
    if (!is_valid_float(*line))
        return (printf("%s %s", msg, INV_FLOAT), false);
    *line = ft_strtof(*line, &data[1]);
    if (**line != ',')
        return (printf("%s %s", msg, MISS_SPACE), false);
    *line = *line + 1;
    if (!is_valid_float(*line))
        return (printf("%s %s", msg, INV_FLOAT), false);
    *line = ft_strtof(*line, &data[2]);
    *value = _mm_load_ps(data);
    if (point)
        return (true);
    return (is_valid_vector(value, -1, 1, msg));
}