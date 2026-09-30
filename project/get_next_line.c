/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcortes <jcortes@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 11:36:44 by jcortes           #+#    #+#             */
/*   Updated: 2026/09/30 09:29:05 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_buff(char *buff)
{
	if (buff != NULL)
	{
		free(buff);
		buff = NULL;
	}
	return (NULL);
}

char	*read_into_buffer(int fd, char *buff)
{
	char	*tmp;
	ssize_t	bytes_read;

	if (buff == NULL)
		buff = ft_strdup("");
	tmp = (char *) malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (free_buff(buff));
	while (buff != NULL && ft_strchr(buff, '\n') == NULL)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_buff(buff), free_buff(tmp));
		if (bytes_read == 0)
		{
			if (buff[0] == '\0')
				return (free_buff(tmp), buff);
			break ;
		}
		tmp[bytes_read] = '\0';
		buff = ft_strjoin(buff, tmp);
		if (buff == NULL)
			return (free_buff(buff), free_buff(tmp));
	}
	return (free_buff(tmp), buff);
}

char	*find_endl(char **buff)
{
	char	*line;
	char	*rest;
	char	*endl;

	if (buff == NULL || *buff == NULL)
		return (NULL);
	endl = ft_strchr(*buff, '\n');
	if (endl != NULL)
	{
		line = ft_substr(*buff, 0, endl - *buff + 1);
		rest = ft_strdup(endl + 1);
		free(*buff);
		*buff = rest;
		if (line == NULL)
			return (free_buff(line));
	}
	else
	{
		line = ft_strdup(*buff);
		free(*buff);
		*buff = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*next;
	static char	*buffs[MAX_FDS];

	if (fd < 0 || fd > MAX_FDS || BUFFER_SIZE <= 0)
		return (NULL);
	buffs[fd] = read_into_buffer(fd, buffs[fd]);
	if (buffs[fd] == NULL)
		return (NULL);
	next = find_endl(&buffs[fd]);
	if (next != NULL && next[0] == '\0')
		return (free_buff(next));
	return (next);
}
