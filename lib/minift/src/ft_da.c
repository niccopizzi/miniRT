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
    ft_memcpy(tmp, da->data + (pos1 * da->bytes), da->bytes);
    ft_memcpy(da->data + (da->bytes * pos1), 
                da->data + (da->bytes * pos2), da->bytes);
    ft_memcpy(da->data + (da->bytes * pos2), tmp,  da->bytes);
}

bool    da_realloc(t_da *da)
{
    char*       data;

    data = malloc(da->bytes * da->size * 2);
    if (!data)
        return (false);
    ft_memcpy(data, da->data, (da->size * da->bytes));
    if (da->data)
        free(da->data);
    da->data = data;
    da->capacity = da->size;
    return (true);
}

bool    da_append(t_da *da, void* object)
{
    if (da->capacity == 0 && !da_realloc(da))
        return (false);
    ft_memcpy(da->data + (da->size * da->bytes), object, da->bytes);
    da->size += 1;
    da->capacity -= 1;
    return (true);
}

bool    da_init(t_da *da, size_t capacity, t_bytes bytes)
{
    da->size = 0;
    da->capacity = capacity;
    da->bytes = bytes;
    da->data = malloc(da->bytes * capacity);
    if (!da->data)
        return (false);
    return (true);
}