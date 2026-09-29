/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:36:44 by jcortes           #+#    #+#             */
/*   Updated: 2026/09/29 17:01:45 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_endl(char *str, size_t size)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (size_t) i < size)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_into_buffer(int fd)
{
	char	*buff;
	ssize_t	bytes_read;

	buff = (char *) malloc(BUFFER_SIZE);
	if (buff)
		return (NULL);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buff);
		return(NULL);
	}
	buff[bytes_read] = '\0';
	return (buff);
}

char	*get_buffer(int fd)
{
	int			endl_idx;
	char		*buff;
	char		*res;
	static char	*prev;

	if (prev == NULL)
	{
		prev = malloc(BUFFER_SIZE);
		if (prev == NULL)
			return (NULL);
		prev[0] = '\0';
	}
	if (ft_strlen(prev) > 0)
	{
		buff = ft_strdup(prev);
		prev[0] = '\0';
	}
	else
		buff = read_into_buffer(fd);
	endl_idx = find_endl(buff, BUFFER_SIZE);
	if (endl_idx == -1)
		return (buff);
	prev = ft_substr(buff, endl_idx + 1, BUFFER_SIZE);
	res = ft_substr(buff, 0, endl_idx);
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*next;
	char		*res;
	int			endl_idx;

	buff = get_buffer(fd);
	if (buff == NULL)
		return (NULL);
	endl_idx = find_endl(buff, BUFFER_SIZE);
	if (endl_idx == -1)
	{
		next = get_buffer(fd);
		if (next == NULL)
		{
			free(buff);
			return (NULL);
		}
		res = ft_strjoin(buff, next);
		free(buff);
		free(next);
		return (res);
	}
	return (buff);
}

/*int	error(int fd)
{
	if (fd != -1)
		close(fd);
	return (1);
}

int	main(void)
{
	#include <stdio.h>
	int fd = open("./project/get_next_line.h", O_RDONLY);
	if (fd == -1)
		return (error(fd));
	int fd2 = open("./project/get_next_line.c", O_RDONLY);
	if (fd2 == -1)
		return (error(fd2));
	char *str;
	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			str = get_next_line(fd);
		else
			str = get_next_line(fd2);
   		 if (str == NULL)
    	    return (error(fd));
	    printf("'%s'\n", str);
	}
	free(str);
	close(fd);
	close(fd2);
}*/
