/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:03:39 by npizzi            #+#    #+#             */
/*   Updated: 2025/03/18 13:11:03 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minift.h"

int	ft_clean_buffer(char *buffer)
{
	int	i;
	int	j;
	int	is_newline;

	i = 0;
	j = 0;
	is_newline = 0;
	while (buffer[i])
	{
		if (is_newline == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			is_newline = 1;
		buffer[i] = 0;
		i++;
	}
	return (is_newline);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	size_t	i;

	res = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (!res)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		res[i++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	res[i] = '\0';
	return (res);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0)
		return (-1);
	if (read(fd, 0, 0) < 0)
	{
		if (fd < 0 || fd >= FOPEN_MAX)
			return (-1);
		buffer[fd][0] = '\0';
		return (-1);
	}
	*line = NULL;
	while ((buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0))
	{
		*line = ft_strjoin_gnl(*line, buffer[fd]);
		if (ft_clean_buffer(buffer[fd]) == 1)
			break ;
	}
	if (*line == NULL)
		return (0);
	return (1);
}