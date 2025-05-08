/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:29:48 by npizzi            #+#    #+#             */
/*   Updated: 2025/04/25 20:14:50 by npizzi           ###   ########.fr       */
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
    if (!da_init(&world.objects, OBJECT_CAPACITY, OBJECT_BYTES))
        return (printf(ERR MALLOC_ERR), 2);
    if (!are_valid_args(argv, &world))
        return(free(world.objects.data), printf("File is not ok!\n"), 3);

    connection_init(&ptrs, &img , &world);
    hooks_set_up(&ptrs);
    mlx_clear_window(ptrs.mlx_ptr, ptrs.win_ptr);
    mlx_put_image_to_window(ptrs.mlx_ptr, ptrs.win_ptr, img.img_ptr, 0, 0);
    mlx_loop(ptrs.mlx_ptr);
    return (0);
}
