/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:26:14 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:02:31 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../lib/minift/include/minift.h"
# include "ray.h"

typedef struct s_shading	t_shading;
typedef struct s_object		t_object;
typedef struct s_world		t_world;

struct						s_object
{
	bool					(*hit)(const t_object *, const t_ray *, double *);
	t_vec4					(*normal_get)(const t_object *, t_shading *);
	void					(*map)(const t_object *, const t_point4, float *u,
			float *v);
	bool					checkered;
	float					radius;
	float					r2;
	float					half_height;
	float					k;
	t_point4				point;
	t_vec4					normal;
	t_vec4					axis;
	t_color					color;
};

typedef struct s_sp_equation
{
	double					a;
	double					b;
	double					c;
	double					discr;
	double					denom;
	double					t;
}							t_sp_equation;

typedef struct s_cy_equation
{
	double					a;
	double					b;
	double					c;
	double					discr;
	double					dv;
	double					xv;
	t_vec4					x;
}							t_cy_equation;

typedef struct s_co_equation
{
	double					a;
	double					b;
	double					c;
	double					discr;
	double					dv;
	double					xv;
	t_vec4					x;
}							t_co_equation;

bool						plane_hit(const t_object *pl, const t_ray *r,
								double *t_min);
bool						sphere_hit(const t_object *sp, const t_ray *r,
								double *t_min);
bool						cylinder_hit(const t_object *cy, const t_ray *r,
								double *t_min);
bool						disk_hit(const t_object *ds, const t_ray *r,
								double *t_min);
bool						cone_hit(const t_object *co, const t_ray *r,
								double *t_min);

t_vec4						sphere_normal(const t_object *obj, t_shading *info);
t_vec4						plane_normal(const t_object *obj, t_shading *info);
t_vec4						cylinder_normal(const t_object *obj,
								t_shading *info);
t_vec4						cone_normal(const t_object *obj, t_shading *info);

void						sphere_map(const t_object *obj, const t_point4 p,
								float *u, float *v);
void						plane_map(const t_object *obj, const t_point4 p,
								float *u, float *v);
void						cylinder_map(const t_object *obj, const t_point4 p,
								float *u, float *v);

bool						check_t(double t, double *t_min);
bool						is_inside_cy(const t_point4 ray_at,
								const t_object *obj);
bool						is_inside_co(const t_point4 ray_at,
								const t_object *obj);

bool						cylinder_add_to_objects(t_object *cy,
								t_world *world);
bool						cone_add_to_objects(t_object *co, t_world *world);
#endif // OBJECTS_H