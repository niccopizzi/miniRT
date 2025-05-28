#include "render.h"

void    create_seed(void)
{
    unsigned short  seed[3];
    
    srand(time(NULL));
    seed[0] = (unsigned short)(rand() & 0xFFFF);
    seed[1] = (unsigned short)(rand() & 0xFFFF);
    seed[2] = (unsigned short)(rand() & 0xFFFF);

    seed48(seed);
}

