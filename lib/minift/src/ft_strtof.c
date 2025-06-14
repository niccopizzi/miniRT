/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:08:14 by npizzi            #+#    #+#             */
/*   Updated: 2025/06/14 14:18:34 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minift.h"

static char	*convert_after_point(char *str, float *f, int sign)
{
	int		i;
	int		len;
	float	atoi;

	i = 0;
	len = 0;
	if (str[i] == '.')
	{
		i++;
		atoi = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			len++;
		}
		*f = *f + (sign) * atoi / pow(10, len);
	}
	return (str + i);
}

char	*ft_strtof(char *str, float *f)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[0] == '+')
		i++;
	*f = ft_atoi(str);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (convert_after_point(str + i, f, sign));
}
