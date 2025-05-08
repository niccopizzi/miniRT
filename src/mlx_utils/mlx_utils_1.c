#include "mlx_utils.h"
#include "miniRT.h"

void connection_init(t_ptrs* ptrs, t_image* img, t_world *world)
{
    ptrs->mlx_ptr = mlx_init();
    if (!ptrs->mlx_ptr)
    {
        printf("Error in starting the connection to the X Server\n");
        exit (EXIT_FAILURE);
    }
    ptrs->win_ptr = mlx_new_window(ptrs->mlx_ptr, WIDTH, HEIGHT, "miniRT");
    if (!ptrs->win_ptr)
    {
        printf("Error in creating the window\n");
        mlx_destroy_display(ptrs->mlx_ptr), free(ptrs->mlx_ptr);
        exit(EXIT_FAILURE);
    }
    img->img_ptr = mlx_new_image(ptrs->mlx_ptr, WIDTH, HEIGHT);
    if (!img->img_ptr)
    {
        printf("Error in creating the image\n");
        mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
        mlx_destroy_display(ptrs->mlx_ptr), free(ptrs->mlx_ptr);
        exit(EXIT_FAILURE);
    }
    ptrs->img = img;
    ptrs->world = world;
    img->img_address = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
                         &img->size_line, &img->endianess);
}

int     convert_to_rgb(t_color* color)
{
    int r;
    int g;
    int b;
    
    r = 255.999 * (*color)[0];
    g = 255.999 * (*color)[1];
    b = 255.999 * (*color)[2];
    return (r << 16 | g << 8 | b);
}

int convert_from_rgb(unsigned char r, unsigned char g, unsigned char b)
{
    return (r << 16 | g << 8 | b);
}

void image_pixel_put(t_image *image, int x, int y, int color)
{
	int offset;
	char *pixel_address;
    
    if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
    {
        return;
    }
	offset = (y * image->size_line) + x * (image->bits_per_pixel / 8);
	pixel_address = (image->img_address) + offset;
	*(unsigned int *)pixel_address = color;
}