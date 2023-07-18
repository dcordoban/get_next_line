/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:19:14 by dcordoba          #+#    #+#             */
/*   Updated: 2023/07/18 22:08:34 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include<unistd.h>
# include<stddef.h>
# include<stdlib.h>
# include<stdio.h>
# include <fcntl.h>
# include"get_next_line_utils.c"


char	*get_next_line(int fd);
size_t	ft_strlen(const char	*s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strchr(const char *s, int c);
char	*free_mem(char *buffer);
char	*ft_substr(char *str, unsigned int start, size_t str_len);

#endif
