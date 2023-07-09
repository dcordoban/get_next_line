/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:32:31 by dcordoba          #+#    #+#             */
/*   Updated: 2023/07/09 19:32:21 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer)
{
	char	*tmp;
	int		readed;

	readed = read(fd, buffer, BUFFER_SIZE);
	if (readed == BUFFER_SIZE)
	{
		tmp = malloc(BUFFER_SIZE + 1*sizeof(char));
		if (!tmp)
		{
			free(*buffer);
			buffer = NULL;
			return (NULL);
		}
		else{
			tmp[readed + 1] = '\0';
			buffer = ft_strjoin(buffer, tmp);
			return (buffer);
		}
	}
	else
	{
		free(*buffer);
		buffer = NULL;
		return (NULL);
	}
	

}
char	*get_next_line(int fd)
{
	static	char*	buffer = {0};
	int				readed;
	char 			*line;
	//check for conditions to return null
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//check for buffer empty or not containing \n
	if (!buffer || (buffer && !ft_strchr(buffer,'\n')))
		buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);

	
	
	//extract from list and return line
	//clean line from list and clean listvoid	read_and_store(t_list **storage, int *readed, int fd)
{
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	readed = read(fd, buffer, BUFFER_SIZE);
}

}