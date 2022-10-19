/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pos31d0n <pos31d0n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:29:47 by phperrot          #+#    #+#             */
/*   Updated: 2022/10/17 13:58:05 by pos31d0n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int				get_next_line(const int fd, char **line);
size_t			ft_strlen_gnl(const char *s);
char			*ft_strchr_gnl(const char *s, int c);
char			*ft_strdup_gnl(const char *s1);
char			*ft_strjoin_gnl(char const *s1, char const *s2);
char			*ft_strsub_gnl(char *str, int start, int len);

#endif
