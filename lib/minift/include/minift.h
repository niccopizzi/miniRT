#ifndef MINIFT_H
#define MINIFT_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

#define BUFFER_SIZE 42

typedef enum e_bytes
{
    OBJECT_BYTES = 160,
}   t_bytes;


typedef struct s_da
{
    char*       data;
    t_bytes     bytes;
    size_t      size;
    size_t      capacity;
}   t_da;

bool    da_init(t_da *da, size_t capacity, t_bytes bytes);
bool    da_realloc(t_da *da);
bool    da_append(t_da *da, void* data);
void    da_pop(t_da *da);
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
#endif // MINIFT_H