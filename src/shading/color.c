#include "world.h"

int     convert_to_rgb(t_color* color)
{
    int r = 255.999 * (*color)[0];
    int g = 255.999 * (*color)[1];
    int b = 255.999 * (*color)[2];
    return (r << 16 | g << 8 | b);
}

float   clamp(float to_clamp, float min, float max)
{
    if (to_clamp < min)
        return (min);
    if (to_clamp > max)
        return (max);
    return (to_clamp);
}