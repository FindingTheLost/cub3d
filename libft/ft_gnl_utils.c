/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-alme <pde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:58:02 by pde-alme          #+#    #+#             */
/*   Updated: 2026/01/29 17:48:41 by pde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This file was previously named "get_next_line_utils_bonus.c" and was changed
 * to fit the libft library naming scheme. It's part of "get_next_line" with
 * bonus.
 */

static size_t	gnl_strlen(char *str)
{
	size_t	index;

	index = 0;
	if (str == NULL)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

static char	*gnl_strchr(char *str, unsigned char c)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return (&str[index]);
		index++;
	}
	if (str[index] == c)
		return (&str[index]);
	return (NULL);
}

static char	*gnl_strjoin(char *s_ptr, char *ptr)
{
	size_t	index;
	size_t	index2;
	char	*tmp;

	index = 0;
	if (ptr == NULL)
	{
		ptr = (char *)malloc(sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[index] = '\0';
	}
	tmp = malloc(sizeof(char) * (gnl_strlen(s_ptr) + gnl_strlen(ptr) + 1));
	if (tmp == NULL)
		return (free(ptr), NULL);
	index2 = 0;
	while (ptr[index] != '\0')
		tmp[index2++] = ptr[index++];
	index = 0;
	while (s_ptr[index] != '\0')
		tmp[index2++] = s_ptr[index++];
	tmp[index2] = '\0';
	free(ptr);
	return (tmp);
}

char	*gnl_trim_string(char *s_ptr, char *ptr)
{
	size_t	index;
	size_t	index2;

	index = 0;
	index2 = 0;
	if (ptr[index] == '\0')
		return (free(ptr), NULL);
	while (ptr[index] != '\0' && ptr[index] != '\n')
		index++;
	if (ptr[index] == '\n')
	{
		index++;
		while (ptr[index] != '\0')
		{
			s_ptr[index2++] = ptr[index];
			ptr[index++] = '\0';
		}
	}
	s_ptr[index2] = '\0';
	return (ptr);
}

char	*gnl_get_string(int fd, char *s_ptr)
{
	char	*ptr;
	int		bytes;

	ptr = NULL;
	bytes = 1;
	if (s_ptr[0] != '\0')
	{
		ptr = gnl_strjoin(s_ptr, ptr);
		if (ptr == NULL)
			return (NULL);
	}
	while (gnl_strchr(s_ptr, '\n') == NULL && bytes != 0)
	{
		bytes = read(fd, s_ptr, BUFFER_SIZE);
		if (bytes == -1)
			return (free(ptr), NULL);
		s_ptr[bytes] = '\0';
		ptr = gnl_strjoin(s_ptr, ptr);
	}
	return (ptr);
}
