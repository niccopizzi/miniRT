/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:29:48 by npizzi            #+#    #+#             */
/*   Updated: 2025/05/14 18:24:17 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int argc, char *argv[])
{
    t_ptrs      ptrs;
    t_image     img;
    t_world     world;

    ft_bzero(&world, sizeof(t_world));
    if (argc == 1 || !argv[1][0])
        return (printf(ERR NO_FILE), 1);
    if (!da_init(&world.objects, OBJECT_CAPACITY, sizeof(t_object)))
        return (printf(ERR MALLOC_ERR), 2);
    if (!are_valid_args(argv, &world))
        return(free(world.objects.data), printf("File is not ok!\n"), 3);
    t_object* ptr = (t_object*)world.objects.data;
    for (size_t i = 0; i < world.objects.size; i++)
    {
        object_material_setup(&ptr[i]);
    }
    connection_init(&ptrs, &img , &world);
    hooks_set_up(&ptrs);
    mlx_clear_window(ptrs.mlx_ptr, ptrs.win_ptr);
    camera_setup(&world.cam);
    render_scene(&ptrs, &world); /*Actual renderer*/
    mlx_loop(ptrs.mlx_ptr);
    return (0);
}
