/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:32:31 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/06 21:55:35 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*storage;
	int				readed;
	//check for conditions to return null
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//read from fd and add to list
	storage = ft_lstnew(NULL);
	read_and_store(&storage, &readed, fd);
	//extract from list and return line
	//clean line from list and clean list
}

void	read_and_store(t_list **storage, int *readed, int fd)
{
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	readed = read(fd, buffer, BUFFER_SIZE);
}