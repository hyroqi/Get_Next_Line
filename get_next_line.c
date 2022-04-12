/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:18:54 by hgabriel          #+#    #+#             */
/*   Updated: 2022/04/13 00:54:23 by hgabriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

static int	read_bytes(int fd, char **buf, int *bytes_read)
{
	int	i;

	i = read(fd, *buf, BUFFER_SIZE);
	*bytes_read = i;
	return (i);
}

static void	freenull(char **str)
{
	if (str)
	{
		free(*str);
		*str = 0;
	}
}

static char	*gnl_output(char **str)
{
	size_t	i;
	char	*ret;
	char	*temp;

	i = 0;
	if (*str)
	{
		while ((*str)[i] && (*str)[i] != '\n')
			i++;
		if ((*str)[i])
		{
			ret = ft_substr(*str, 0, i + 1);
			temp = ft_substr(*str, i + 1, ft_strlen(*str));
			freenull(str);
			if (temp[0] != '\0')
				*str = temp;
			else
				freenull(&temp);
		}
		else
		{
			ret = ft_substr(*str, 0, ft_strlen(*str));
			freenull(str);
		}
		return (ret);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buff;
	char		*temp;
	int			bytes_read;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd >= 0 && BUFFER_SIZE > 0 && (buff))
	{
		while (read_bytes(fd, &buff, &bytes_read) > 0)
		{
			buff[bytes_read] = 0;
			if (!hold)
				hold = ft_bzero(0);
			temp = ft_strjoin(hold, buff);
			free(hold);
			hold = temp;
			if (find_nl(buff))
				break ;
		}
		free(buff);
		return (gnl_output(&hold));
	}
	free(buff);
	return (NULL);
}
