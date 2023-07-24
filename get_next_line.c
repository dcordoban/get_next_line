/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:32:31 by dcordoba          #+#    #+#             */
/*   Updated: 2023/07/24 23:08:41 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_mem(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

char	*read_line(int fd, char *buffer)
{
	char	*tmp;
	int		readed;

	tmp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!tmp)
		return (ft_free(buffer));
	tmp[0] = '\0';
	readed = read(fd, tmp, BUFFER_SIZE);
	if (readed > 0)
	{
		tmp[readed] = '\0';
		if (!buffer)
			buffer = "\0";
		buffer = ft_strjoin(buffer, tmp);
	}
	else if (readed == -1)
	{
		ft_free(tmp);
		return (ft_free(buffer));
	}
	free(tmp);
	tmp = NULL;
	return (buffer);
}

char	*extract_line(char *line, char **buffer)
{
	int	match;
	int	buff_len;

	buff_len = ft_strlen(*buffer);
	match = ft_strchr(*buffer, '\n');
	if (match == 0 || match + 1 == buff_len)
	{
		line = ft_substr(*buffer, 0, buff_len + 1);
		free_mem(buffer);
	}
	else
	{
		line = ft_substr(*buffer, 0, match + 1);
		if (!line)
			free_mem(buffer);
		else
			*buffer = ft_substr(*buffer, match + 1, buff_len - match);
		if (!*buffer)
			*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		ft_free(buffer);
	line = NULL;
	if (!buffer)
		buffer = NULL;
	if (!buffer || (buffer && !ft_strchr(buffer, '\n')))
		buffer = read_line(fd, buffer);
	if ((buffer && ft_strchr(buffer, '\n'))
		|| (buffer && ft_strlen(buffer) == 1))
		line = extract_line(line, &buffer);
	if (!line)
		ft_free(line);
	return (line);
}
