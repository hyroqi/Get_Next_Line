/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leu-lee <leu-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:18:58 by hgabriel          #+#    #+#             */
/*   Updated: 2022/04/11 11:35:25 by leu-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*find_nl(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(const char *str, size_t start, size_t len);
char	*ft_bzero(size_t size);

#endif