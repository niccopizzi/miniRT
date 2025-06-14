/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:34:10 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 13:38:59 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../lib/minift/include/minift.h"
# include "objects.h"
# include "world.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>

# define ERR "Error: "

# define A_LIGHT "Ambient lightning: "
# define CAM "Camera: "
# define LIGHT "Light: "
# define SPHERE "Sphere: "
# define PLANE "Plane: "
# define CYLINDER "Cylinder: "
# define CONE "Cone : "
# define RATIO "ratio: "
# define FOV "field of view: "
# define O_VEC "orientation vector: "
# define NORMAL "normal: "
# define CENTER "center: "
# define COOR "coordinates values: "

# define UNKOWN_INPUT "input provided not recognized\n"

# define RGB_ERR "RGB values not valid\n"

# define INV_FLOAT "float not valid\n"
# define INV_VECTOR "vector cannot be 0,0,0\n"
# define OOR "value out of range\n"
# define POINT_FORMAT "coordinates not in format x,y,z\n"

# define NO_ARG "no arg provided\n"
# define FILE_NOT_VALID "file not valid\n"
# define MULT "cannot have more than 1\n"
# define MISS_VAL "missing values\n"
# define MISS_DECL "missing declaration\n"
# define MISS_SPACE "missing space after values\n"
# define FORMAT_ERR "format not correct, expecting comma after value\n"
# define ENDLINE_ERR "expected endline after values\n"
# define CHECKER_ERR "expected 'c' identifier\n"
# define MALLOC_ERR "malloc failed\n"

// PARSE UTILS
bool	is_valid_file(char *filename, t_world *world);
bool	skip_space_and_check(char **line, char *msg);
bool	is_valid_float(char *line);
bool	is_valid_vector(t_vec4 *vec, float min, float max, char *msg);
bool	check_if_declared(int *declared);

// PARSE FUNCTIONS

bool	parse_on_identifier(char *trim, t_world *world, int *declared);
bool	parse_file(int fd, t_world *world);
bool	parse_rgb(char **line, t_color *color);
bool	parse_texture(char **line, t_object *obj, char *msg);
bool	parse_vector_or_point(char **line, t_vec4 *value, float point, char *m);

bool	parse_sphere(char *line, t_world *world);
bool	parse_plane(char *line, t_world *world);
bool	parse_cylinder(char *line, t_world *world);
bool	parse_cone(char *line, t_world *world);
#endif // PARSING_H
