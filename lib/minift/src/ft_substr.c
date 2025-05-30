/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:03:07 by nicco             #+#    #+#             */
/*   Updated: 2025/05/30 09:13:58 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minift.h"

static void	cpy_str(char *substr, char const *s, unsigned int start, size_t len)
{
	unsigned int	i;

	i = 0;
	if (start <= ft_strlen(s))
	{
		while (i < len && s[start + i] != 0)
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	substr[i] = 0;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	x;

	if (s == NULL)
		return (NULL);
	x = ft_strlen(s);
	if (s + start > s + x)
		substring = (char *)malloc(1);
	else if (start == (x - 1))
		substring = (char *)malloc(2);
	else if (len >= x)
		substring = (char *)malloc((x * sizeof(char)) + 1);
	else
		substring = (char *)malloc((len * sizeof(char)) + 1);
	if (substring == NULL)
		return (NULL);
	cpy_str(substring, s, start, len);
	return (substring);
}
