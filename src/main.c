/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:29:48 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/03 18:24:24 by npizzi           ###   ########.fr       */
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
        return (printf(ERR NO_ARG), 1);
    if (ft_strncmp("-h", argv[1], 3) == 0)
        return (usage_print());
    if (!da_init(&world.objects, OBJECTS_CAPACITY, sizeof(t_object)))
        return (printf(ERR MALLOC_ERR), 2);
    if (!da_init(&world.light, LIGHTS_CAPACITY, sizeof(t_light)))
        return (printf(ERR MALLOC_ERR), free(world.objects.data), 3);
    if (!is_valid_file(argv[1], &world))
        return(free_world_data(&world), 3);
    connection_init(&ptrs, &img , &world);
    ptrs.filename = argv[1];
    hooks_set_up(&ptrs);
    mlx_clear_window(ptrs.mlx_ptr, ptrs.win_ptr);
    world_setup(&world);
    create_seed();
    render_scene(&ptrs, &world); 
    mlx_loop(ptrs.mlx_ptr);
}
