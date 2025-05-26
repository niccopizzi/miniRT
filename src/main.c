/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:29:48 by npizzi            #+#    #+#             */
/*   Updated: 2025/05/26 20:11:56 by npizzi           ###   ########.fr       */
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
    if (!is_valid_file(argv[1], &world))
        return(free(world.objects.data), 3);
    connection_init(&ptrs, &img , &world);
    ptrs.filename = argv[1];
    hooks_set_up(&ptrs);
    mlx_clear_window(ptrs.mlx_ptr, ptrs.win_ptr);
    world_setup(&world);
    render_scene(&ptrs, &world); /*Actual renderer*/
    mlx_loop(ptrs.mlx_ptr);
}
