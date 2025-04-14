#include "minift.h"

char    *ft_strtof(char *str, float *f)
{
    int i;
	int	len;
    float atoi;
    int sign;

    i = 0;
    sign = 1;
	len = 0;
    if (str[0] == '-')
        sign = -1, i++;
	else if (str[0] == '+')
		i++;
    *f = ft_atoi(str);
    while(str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == '.')
    {
		i++;
        atoi = ft_atoi(str + i);
        while (str[i] >= '0' && str[i] <= '9')
            i++, len++;
        *f = *f + (sign) * atoi / pow(10, len);
    }
    return (str + i);
}