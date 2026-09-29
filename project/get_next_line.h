/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:35:19 by jcortes           #+#    #+#             */
/*   Updated: 2026/09/29 18:53:19 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(char const *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *str, int c);

char		*get_next_line(int fd);

#endif
