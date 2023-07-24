/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:25:31 by dcordoba          #+#    #+#             */
/*   Updated: 2023/07/24 23:02:32 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_to_dst;
	const unsigned char	*ptr_to_src;

	ptr_to_src = (unsigned char *) src;
	ptr_to_dst = (unsigned char *) dest;
	if (!ptr_to_dst && !ptr_to_src)
		return (ptr_to_dst);
	while (n-- > 0)
		*(ptr_to_dst++) = *(ptr_to_src++);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	size_t	t_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	t_len = s1_len + s2_len;
	j_str = (char *)malloc((t_len + 1) * sizeof(char));
	if (j_str)
	{
		if (t_len == 0)
			j_str[0] = 0;
		else
		{
			ft_memcpy(j_str, s1, s1_len);
			while (i < s2_len)
				j_str[s1_len++] = s2[i++];
		j_str[t_len] = '\0';
		}
		return (j_str);
	}
	return (0);
}

size_t	ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	to_find;
	size_t			s_len;

	i = 0;
	to_find = (unsigned char) c;
	s_len = ft_strlen(s);
	while (i <= s_len)
	{
		if (s[i] == to_find)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (0);
	if (start > ft_strlen(s))
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (start < ft_strlen(s) && i < len && &s[start])
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
