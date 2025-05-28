#ifndef MINIFT_H
#define MINIFT_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

#define BUFFER_SIZE 42

typedef struct s_da
{
    char*       data;
    size_t      bytes;
    size_t      size;
    size_t      capacity;
}   t_da;


/**
 * @brief Initialize the dynamic array.
 *
 * This function takes a pointer to a dynamic array and initializes it allocating the necessary bytes, it return false if malloc failed.
 *
 * @param da Pointer to the dynamic array.
 * @param capacity The total elements the array can store.
 * @param bytes The amount of bytes the single elements occupy in memory.
 * @return True if allocation of memory was succesful, False otherwise.
 */
bool    da_init(t_da *da, size_t capacity, size_t bytes);

/**
 * @brief Resize the dynamic array.
 *
 * This function takes a pointer to a dynamic array that is full and resizes it allocating a new block of memory, it return false if malloc failed.
 *
 * @param da Pointer to the dynamic array.
 * @return True if allocation of memory was succesful, False otherwise.
 */

bool    da_realloc(t_da *da);
/**
 * @brief Append the data to the dynamic array.
 *
 * This function takes a pointer to a dynamic array and to the data to be stored and appends the data to the end of the array, resizing the array if there's not enough space, it return false if malloc failed.
 *
 * @param da Pointer to the dynamic array.
 * @param data Pointer to the data to be stored.
 * @return True if allocation of memory was succesful, False otherwise.
 */
bool    da_append(t_da *da, void* data);

/**
 * @brief Pop the last element of the dynamic array.
 *
 * This function takes a pointer to a dynamic array and pops the last data that was stored.
 *
 * @param da Pointer to the dynamic array.
 */
void    da_pop(t_da *da);

/**
 * @brief Swap two element in a dynamic array.
 *
 * This function takes a pointer to a dynamic array and the positions of the elements to be swapped.
 *
 * @param da Pointer to the dynamic array.
 * @param pos1 The position of the first element.
 * @param pos2 The position of the second element.
 */
void    da_swap(t_da *da, size_t pos1, size_t pos2);

bool	ft_isspace(char c);
int	    ft_atoi(const char *nptr);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int	    get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char    *ft_strtof(char *str, float *f);
char	*ft_strnstr(const char *big, const char *little, size_t n);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
#endif // MINIFT_H