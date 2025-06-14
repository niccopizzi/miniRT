/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:21:59 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 15:23:33 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx_utils.h"

void	free_and_exit(void *mlx_ptr, void *win_ptr, t_world *world, char *msg)
{
	printf("%s", msg);
	free_world_data(world);
	if (win_ptr)
		mlx_destroy_window(mlx_ptr, win_ptr);
	if (mlx_ptr)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
	}
	exit(EXIT_FAILURE);
}

void	connection_init(t_ptrs *ptrs, t_image *img, t_world *world)
{
	ptrs->mlx_ptr = mlx_init();
	if (!ptrs->mlx_ptr)
		free_and_exit(NULL, NULL, world, DISPLAY_ERR);
	ptrs->win_ptr = mlx_new_window(ptrs->mlx_ptr, WIDTH, HEIGHT, "miniRT");
	if (!ptrs->win_ptr)
		free_and_exit(ptrs->mlx_ptr, NULL, world, WIN_ERR);
	img->img_ptr = mlx_new_image(ptrs->mlx_ptr, WIDTH, HEIGHT);
	if (!img->img_ptr)
		free_and_exit(ptrs->mlx_ptr, ptrs->win_ptr, ptrs->world, IMG_ERR);
	ptrs->img = img;
	ptrs->world = world;
	img->img_address = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endianess);
}

int	to_rgb(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = fminf(255.999 * (color)[0], 255);
	g = fminf(255.999 * (color)[1], 255);
	b = fminf(255.999 * (color)[2], 255);
	return (r << 16 | g << 8 | b);
}

int	convert_from_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	int		offset;
	char	*pixel_address;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
	{
		return ;
	}
	offset = (y * image->size_line) + x * (image->bits_per_pixel / 8);
	pixel_address = (image->img_address) + offset;
	*(unsigned int *)pixel_address = color;
}
