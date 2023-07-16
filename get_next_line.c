/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:32:31 by dcordoba          #+#    #+#             */
/*   Updated: 2023/07/10 18:33:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer)
{
	char	*tmp;
	int		readed;

	
	tmp = malloc(BUFFER_SIZE + 1*sizeof(char));
	readed = read(fd, tmp, BUFFER_SIZE);
	if (readed == BUFFER_SIZE)
	{
		if (!tmp)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		else{
			tmp[readed + 1] = '\0';
			if (!buffer)
				buffer = "\0";
			buffer = ft_strjoin(buffer, tmp);
			return (buffer);
		}
	}
	else
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}


}
char	*get_next_line(int fd)
{
	static	char*	buffer;
	//int				readed;
	//char 			*line;
	//check for conditions to return null
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//check for buffer empty or not containing \n
	if (!buffer || (buffer && !ft_strchr(buffer,'\n')))
		buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);

	return (buffer);

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
