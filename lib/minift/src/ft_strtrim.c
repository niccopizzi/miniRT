/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:36:56 by thopgood          #+#    #+#             */
/*   Updated: 2025/05/30 09:11:29 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minift.h"

/*
 * Returns a malloc allocated copy of s1 with the chars from set removed
 * from the beginning and end.
 * Returns a ptr to the trimmed string or NULL if it fails
 */

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

/* #include <stdio.h>

int	main(void)
{
	char const	*set;
	char const	*str;
	char		*out;

	set = "a";
	str = "";
	out = NULL;
	out = ft_strtrim(str, set);
	ft_printf("%s\n", out);
} */
