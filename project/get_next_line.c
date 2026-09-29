/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:36:44 by jcortes           #+#    #+#             */
/*   Updated: 2026/09/29 12:47:50 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	char	*buff;
	size_t	size;
	ssize_t	bytes_read;	

	size = BUFFER_SIZE || 100;
	buff = (char *) malloc(size * sizeof(char));
	if (buff == NULL)
		return (NULL);
	bytes_read = read(fd, buff, size - 1);
	if (bytes_read == 0)
		return (buff);
	buff[size] = '\0';
	endl_idx = find_endl(buff, size);
	return (buff);
}

int	error(int fd)
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
}
