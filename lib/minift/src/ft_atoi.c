/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:29:49 by nicco             #+#    #+#             */
/*   Updated: 2025/03/18 13:19:35 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minift.h"

int	ft_atoi(const char *nptr)
{
	int	atoi;
	int	i;
	int	sign;

	atoi = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		atoi = (atoi * 10) + (nptr[i] - 48);
		i++;
	}
	return (atoi * sign);
}
