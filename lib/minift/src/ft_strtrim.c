/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:16:13 by nicco             #+#    #+#             */
/*   Updated: 2025/03/18 13:20:25 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minift.h"

static int	is_inset(char c, char const *set)
{
	int	i;

	i = 0;
	if (set == NULL)
		return (0);
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	copy_str(char *dest, const char *src, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	i;
	size_t	x;

	if (s1 == NULL)
		return (NULL);
	x = ft_strlen(s1);
	i = 0;
	while (is_inset(s1[i], set) == 1)
		i++;
	while (is_inset(s1[x - 1], set) == 1)
		x--;
	if (x == 0)
		return (ft_strdup(""));
	newstr = (char *)malloc((x - i + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	copy_str(newstr, s1, i, x);
	return (newstr);
}
