#ifndef MINIRT_H
#define MINIRT_H

#define OBJECT_CAPACITY 20

#ifndef BONUS
    #define BONUS 1
#endif

#include <time.h>
#include "ray.h"
#include "mlx_utils.h"
#include "parsing.h"
#include "matrix.h"
#include "render.h"

int    usage_print(void);

#endif // MINIRT_H