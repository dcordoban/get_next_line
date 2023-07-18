/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:32:31 by dcordoba          #+#    #+#             */
/*   Updated: 2023/07/18 22:07:42 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_mem(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*read_line(int fd, char *buffer)
{
	char	*tmp;
	int		readed;

	tmp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	readed = read(fd, tmp, BUFFER_SIZE);
	if (readed == BUFFER_SIZE)
	{
		if (!tmp)
			return (free_mem(buffer));
		else
		{
			tmp[readed + 1] = '\0';
			if (!buffer)
				buffer = "\0";
			buffer = ft_strjoin(buffer, tmp);
			return (buffer);
		}
	}
	else
		return (free_mem(buffer));
}

char	*extract_line(char *line, char **buffer)
{
	int	match;
	int	buff_len;

	buff_len = ft_strlen(*buffer);
	match = ft_strchr(*buffer, '\n');
	if (match == -1 || match + 1 == buff_len)
	{
		line = *buffer;
		*buffer = free_mem(*buffer);
	}
	else
	{
		line = ft_substr(*buffer, 0, match + 1);
		if (!line)
			free_mem(*buffer);
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

	
	//check for conditions to return null
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!buffer)
		buffer = NULL;
	//check for buffer empty or not containing \n
	if (!buffer || (buffer && !ft_strchr(buffer, '\n')))
		buffer = read_line(fd, buffer);
	if (buffer)
		line = extract_line(line, &buffer);
	if (*line == '\0')
		line = free_mem(line);

	return (line);

	//extract from list and return line
	//clean line from list and clean listvoid	read_and_store(t_list **storage, int *readed, int fd)
}
int	main(int argc, char **argv)
{
	int	fd;
	int i = 6;
	char *str;

	if (argc == 50)
		return (2);
	fd = open(argv[1], O_RDONLY);
	while (i-- > 0)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	close(fd);
	return (0);
}
