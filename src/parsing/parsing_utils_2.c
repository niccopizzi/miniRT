/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:25:15 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:38:54 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	parse_texture(char **line, t_object *obj, char *msg)
{
	if (**line == 0)
		return (true);
	if (!skip_space_and_check(line, msg))
		return (false);
	if (**line != 'c')
		return (printf("%s%s", msg, CHECKER_ERR), false);
	*line += 1;
	if (**line != 0)
		return (printf("%s%s", msg, UNKOWN_INPUT), false);
	obj->checkered = true;
	return (true);
}

bool	is_valid_vector(t_vec4 *vec, float min, float max, char *msg)
{
	if (!vector_in_range(*vec, min, max))
	{
		printf("%s%s", msg, OOR);
		return (false);
	}
	if (vector_compare_eq(*vec, vector_from_float(0.f)))
	{
		printf("%s%s", msg, INV_VECTOR);
		return (false);
	}
	return (true);
}

bool	check_if_declared(int *declared)
{
	if (!declared[0])
		return (printf(ERR A_LIGHT MISS_DECL), false);
	if (!declared[1])
		return (printf(ERR CAM MISS_DECL), false);
	if (!declared[2])
		return (printf(ERR LIGHT MISS_DECL), false);
	return (true);
}
