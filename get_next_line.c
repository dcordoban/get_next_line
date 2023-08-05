/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:32:31 by dcordoba          #+#    #+#             */
/*   Updated: 2023/07/28 20:57:14 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_mem(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*return_line(char *buffer)
{
	int		match;
	int		buff_len;
	char	*tmp;

	buff_len = ft_strlen(buffer);
	match = ft_strchr(buffer, '\n');
	if (match >= 0)
		tmp = ft_substr(buffer, 0, match + 1);
	else if (buff_len > 0)
		tmp = ft_substr(buffer, 0, buff_len);
	else
		return (NULL);
	return (tmp);
}

char	*read_input(int fd, char *buffer)
{
	char	*tmp;
	int		readed;

	readed = 1;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (free_mem(&buffer));
	tmp[0] = '\0';
	while (readed > 0 && ft_strchr(tmp, '\n') < 0)
	{
		readed = read(fd, tmp, BUFFER_SIZE);
		if (readed > 0)
		{
			tmp[readed] = '\0';
			buffer = ft_strjoin(buffer, tmp);
		}
	}
	free_mem(&tmp);
	if (readed == -1)
		return (free_mem(&buffer));
	return (buffer);
}

char	*clear_buffer(char *buffer)
{
	int		match;
	int		buff_len;
	char	*tmp;

	match = ft_strchr(buffer, '\n');
	if (match < 0)
	{
		tmp = NULL;
		return (free_mem(&buffer));
	}
	else
		buff_len = ft_strlen(buffer);
	tmp = ft_substr(buffer, match + 1, buff_len - match);
	free_mem(&buffer);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!storage || (storage && ft_strchr(storage, '\n') == -1))
		storage = read_input (fd, storage);
	if (!storage)
		return (free_mem(&storage));
	line = return_line(storage);
	if (!line)
		return (free_mem(&storage));
	storage = clear_buffer(storage);
	return (line);
}
