/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:38:11 by aalahyan          #+#    #+#             */
/*   Updated: 2024/11/20 20:03:00 by aalahyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *rest, const char *buffer)
{
	char	*joined_str;
	int		l1;
	int		l2;

	l1 = 0;
	l2 = 0;
	if (rest)
		l1 = (int)ft_strlen(rest);
	if (buffer)
		l2 = (int)ft_strlen(buffer);
	joined_str = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!joined_str)
	{
		if (rest)
			free(rest);
		return (NULL);
	}
	if (rest)
		ft_memcpy(joined_str, rest, l1);
	if (buffer)
		ft_memcpy(joined_str + l1, buffer, l2);
	joined_str[l1 + l2] = 0;
	if (rest)
		free(rest);
	return (joined_str);
}

int	contains_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
