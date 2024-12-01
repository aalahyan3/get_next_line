/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:59 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/21 15:08:03 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_and_null(void *p1, void *p2)
{
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	return (NULL);
}

char	*extract_rest(char *rest, int fd)
{
	char	*buffer;
	int		ret_val;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_and_null(rest, NULL));
	ret_val = 1;
	while (!contains_new_line(rest) && ret_val != 0)
	{
		ret_val = (int)read(fd, buffer, BUFFER_SIZE);
		if (ret_val < 0)
			return (free_and_null(buffer, rest));
		buffer[ret_val] = 0;
		rest = ft_strjoin(rest, buffer);
		if (!rest)
			return (free_and_null(buffer, NULL));
	}
	free(buffer);
	return (rest);
}

char	*extract_line(char *rest)
{
	char	*line;
	int		i;
	int		size;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		size = i + 2;
	else
		size = i + 1;
	line = malloc(sizeof(char) * size);
	if (!line)
		return (NULL);
	ft_memcpy(line, rest, i);
	if (rest[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*generate_new_rest(char *rest)
{
	char	*new_rest;
	int		i;

	i = 0;
	new_rest = NULL;
	if (!rest)
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		new_rest = ft_strdup(rest + i + 1);
	free(rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest_arr[OPEN_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	rest_arr[fd] = extract_rest(rest_arr[fd], fd);
	if (!rest_arr[fd])
		return (NULL);
	line = extract_line(rest_arr[fd]);
	rest_arr[fd] = generate_new_rest(rest_arr[fd]);
	if (!line || !(*line))
		return (free_and_null(line, rest_arr[fd]));
	return (line);
}
