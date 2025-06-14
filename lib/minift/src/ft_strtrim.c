/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:36:56 by thopgood          #+#    #+#             */
/*   Updated: 2025/06/14 14:16:39 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minift.h"

static size_t	ft_offsetstart(const char *str, char const *set)
{
	size_t	offset_start;

	offset_start = 0;
	while (*str && ft_strchr(set, *str++) && str)
		offset_start++;
	return (offset_start);
}

static size_t	ft_offsetend(const char *str, char const *set, size_t len)
{
	size_t	offset_end;

	offset_end = 0;
	while (*str && ft_strchr(set, str[len - 1]) && len-- > 0)
		offset_end++;
	return (offset_end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;
	size_t	offset_start;
	size_t	offset_end;

	if (s1 == NULL)
		return (NULL);
	s_len = ft_strlen(s1);
	offset_start = ft_offsetstart(s1, set);
	if (offset_start == s_len)
		return (ft_strdup(""));
	offset_end = ft_offsetend(s1, set, s_len);
	s_len = s_len - offset_start - offset_end;
	return (ft_substr(s1, offset_start, s_len));
}
