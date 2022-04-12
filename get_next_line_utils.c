/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:18:51 by hgabriel          #+#    #+#             */
/*   Updated: 2022/04/11 11:36:18 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

char	*find_nl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		combstrlen;
	char	*buffer;
	char	*finalstr;

	combstrlen = (ft_strlen(s1) + ft_strlen(s2));
	if (s1 && s2)
	{
		buffer = (char *)malloc((combstrlen + 1) * sizeof(char));
		if (buffer)
		{
			finalstr = buffer;
			while (*s1 != '\0')
				*buffer++ = *s1++;
			while (*s2 != '\0')
				*buffer++ = *s2++;
			*buffer = '\0';
			return (finalstr);
		}
		return (NULL);
	}
	return (NULL);
}

char	*ft_substr(const char *str, size_t start, size_t len)
{
	char	*res;
	size_t	i;

	if (!str)
		return (0);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (start < len)
		res[i++] = str[start++];
	res[i] = 0;
	return (res);
}

char	*ft_bzero(size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < size + 1)
	{
		*(char *)(res + i) = 0;
		i++;
	}
	return (res);
}
