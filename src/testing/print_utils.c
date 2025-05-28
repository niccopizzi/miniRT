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

int usage_print(void)
{
    printf("Welcome to miniRT!\n");
    printf("Usage: miniRT [options] <filename>\n\n");

    printf("Options:\n");
    printf("  -h              Display this help text and exit\n\n");

    printf("Render Commands:\n");
    printf("  r               Re-parse the scene file and render again\n");
    printf("  c               Toggle camera control between movement and rotation\n");
    printf("  l               Enable light movement\n");
    printf("  Mouse Left      Move the light to the mouse click location (if enabled)\n");
    printf("  +               Zoom in\n");
    printf("  -               Zoom out\n");
    printf("  Arrow Keys      Move or rotate the camera based on the current mode\n");

    return (0);
}


void    print_world(t_world *world)
{
    vector_print("Ambient color", world->ambient);
    vector_print("Light pos", world->lights.pos);
    vector_print("Light color", world->lights.color);
    vector_print("Cam origin", world->cam.origin);
    //t_object *ptr = (t_object*)world->objects.data;
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