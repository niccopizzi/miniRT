#ifndef PARSING_H
#define PARSING_H

#include "../lib/minift/include/minift.h"
#include "world.h"
#include "ray.h"
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

#define ERR "Error: "

#define A_LIGHT "Ambient lightning: "
#define CAM "Camera: "
#define LIGHT "Light: "
#define SPHERE "Sphere: "
#define PLANE "Plane: "
#define CYLINDER "Cylinder: "
#define RATIO "ratio: "
#define FOV "field of view: "
#define O_VEC "orientation vector: "
#define NORMAL "normal: "
#define CENTER "center: "
#define COOR "coordinates values: "

#define UNKOWN_INPUT "input provided not recognized\n"

#define RGB_ERR "RGB values not valid\n"

#define INV_FLOAT "float not valid\n"
#define INV_VECTOR "vector cannot be 0,0,0\n"
#define OOR "value out of range\n"
#define POINT_FORMAT "coordinates not in format x,y,z\n"

#define NO_FILE "no rt file provided\n"
#define FILE_NOT_VALID "file not valid\n"
#define MULT "cannot have more than 1\n"
#define MISS_VAL "missing values\n"
#define MISS_SPACE "missing space after values\n"
#define ENDLINE_ERR "expected endline after values\n"
#define MALLOC_ERR "malloc failed\n"

//PARSE UTILS
bool    are_valid_args(char *argv[], t_world *world);
bool    skip_space_and_check(char **line, char *msg);
bool    is_valid_float(char *line);
bool    is_valid_vector(t_vec4 *vec, float min, float max, char *msg);


//PARSE FUNCTIONS
bool    parse_file(int fd, t_world *world);
bool    parse_rgb(char **line, t_color *color);
bool    parse_vector_or_point(char **line, t_vec4* value, 
                                float point, char *msg);

bool    parse_sphere(char *line, t_world *world);
bool    parse_plane(char *line, t_world *world);
bool    parse_cylinder(char *line, t_world *world);

#endif // PARSING_H
