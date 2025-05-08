#include "minift.h"

void    da_pop(t_da *da)
{
    da->size -= 1;
    da->capacity += 1;
}

void    da_swap(t_da *da, size_t pos1, size_t pos2)
{
    char   tmp[da->bytes];

    if (pos1 >= da->size || pos2 >= da->size)
        return ;
    ft_memcpy(tmp, da->data + (pos1 * da->bytes), da->bytes); /*save the bytes in pos1 in a temporary buffer*/
    ft_memcpy(da->data + (da->bytes * pos1), 
                da->data + (da->bytes * pos2), da->bytes); /*copy the bytes in pos2 to pos1 */
    ft_memcpy(da->data + (da->bytes * pos2), tmp,  da->bytes); /*copy the bytes saved in the tmp buffer to pos2*/
}

bool    da_realloc(t_da *da)
{
    char*       data;

    data = malloc(da->bytes * da->size * 2); /*Allocate more memory than needed so more elements can be stored before having to reallocate again*/
    if (!data)
        return (false);
    ft_memcpy(data, da->data, (da->size * da->bytes)); /*To reallocate the memory we just need to copy the previous stored into the new memory allocated, the amount of bytes to copy is given by the
                                                            elements in the array (da->size) times the bytes they occupy in memory (da->bytes)*/
    if (da->data)
        free(da->data);
    da->data = data;
    da->capacity = da->size; /*update the capacity*/
    return (true);
}

bool    da_append(t_da *da, void* object)
{
    if (da->capacity == 0 && !da_realloc(da)) /*If the array is full resize it*/
        return (false);
    ft_memcpy(da->data + (da->size * da->bytes), object, da->bytes);
    da->size += 1; /*1 element is added to the array*/
    da->capacity -= 1; /*The array now can store 1 less element*/
    return (true);
}

bool    da_init(t_da *da, size_t capacity, size_t bytes)
{
    da->size = 0; /*Initially the array has no elements*/
    da->capacity = capacity;
    da->bytes = bytes;
    da->data = malloc(da->bytes * capacity);
    if (!da->data)
        return (false);
    return (true);
}