/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:39:13 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 13:40:01 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

# include "mlx_utils.h"
# include "ray.h"

# define SAMPLE_SIZE 20

typedef struct s_world	t_world;

void					create_seed(void);
float					generate_random_x(int x, float scale);
float					generate_random_y(int y, float scale);
t_color					sample_pixel(int x, int y, const t_world *world,
							t_ray *r);

#endif