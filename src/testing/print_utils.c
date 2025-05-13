#include "world.h"
#include "matrix.h"
#include "objects.h"

void    matrix_print(t_mat4 id, int size, char *name)
{
    printf("\t\tPRINTING MATRIX : %s\n", name);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%.5f ", id.row[i][j]);
        }
        printf("\n");
    }
}

void    vector_print(char* name, t_vec4 v)
{
    printf("Printing vector : %s\n%f %f %f %f\n", name, v[0], v[1], v[2], v[3]);
}

void    print_world(t_world *world)
{
    printf("AMBIENT LIGHT\nCOLOR: %f %f %f\nRATIO: %f\n",
     world->a_light.color[0], world->a_light.color[1], world->a_light.color[2], 
     world->a_light.ratio);
    printf("LIGHT\nPOS %f %f %f\nCOLOR %f %f %f\nBRIGHTNESS %f\n", 
    world->light_src.pos[0], world->light_src.pos[1], world->light_src.pos[2],
    world->light_src.color[0],world->light_src.color[1], world->light_src.color[2], 
    world->light_src.brightness);
    printf("CAM\nORIGIN %f %f %f\nFORWARD %f %f %f\n", 
            world->cam.origin[0], world->cam.origin[1], world->cam.origin[2],
            world->cam.forward[0], world->cam.forward[1], world->cam.forward[2]);
    t_object *ptr = (t_object*)world->objects.data;
    /* for (size_t i; i < world->objects.size; i++)
    {
        switch (ptr[i].type)
        {
        case SP:
            printf("\n\nSPHERE\nCENTER: %f %f %f\nDIAMETER: %f\nRGB: %f %f %f\n", 
            ptr[i].center[0],ptr[i].center[1],ptr[i].center[2],
            ptr[i].radius, ptr[i].color[0], ptr[i].color[1], ptr[i].color[2]);
            break;
        case PL:
            printf("\n\nPLANE\nPOINT: %f %f %f\nNORMAL %f %f %f\nRGB: %f %f %f\n", 
            ptr[i].point[0], ptr[i].point[1], ptr[i].point[2], 
            ptr[i].normal[0],ptr[i].normal[1], ptr[i].normal[2], 
            ptr[i].color[0], ptr[i].color[1],  ptr[i].color[2]);
            break;
        case CY:
            printf("\n\nCYLINDER\nCENTER: %f %f %f\nAXIS: %f %f %f\nDIAMETER: %f\nHEIGHT: %f\nRGB: %f %f %f\n", 
            ptr[i].center[0], ptr[i].center[1], ptr[i].center[2],
            ptr[i].axis[0], ptr[i].axis[1], ptr[i].axis[2], 
            ptr[i].radius, ptr[i].height, 
            ptr[i].color[0], ptr[i].color[1], ptr[i].color[2]);
            break;
        default:
            printf("ERROR   \n");
            break;
        }
    } */
}