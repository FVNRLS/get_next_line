/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:21:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/08 20:42:53 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gn_realloc_buf(char *buf)
{
	char	*new_buf;
	int		i;
	int		j;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	new_buf = malloc(sizeof(char) * (gn_strlen(buf) - i + 1));
	if (!new_buf)
		return (NULL);
	j = 0;
	i++;
	while (buf[i] != '\0')
		new_buf[j++] = buf[i++];
	new_buf[j] = '\0';
	gn_free_buf(&buf);
	return (new_buf);
}

char	*gn_extract_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	if (buf[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*gn_read_to_buf(char *buf, int fd)
{
	char	*tmp;
	int		read_again;
	int		bytes;

	if (!buf)
		buf = gn_create_buf(buf);
	read_again = 1;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (read_again == 1)
	{
		if (gn_find_newline(buf) == 1)
			break ;
		bytes = read(fd, tmp, BUFFER_SIZE);
		tmp[bytes] = '\0';
		buf = gn_join_buf(buf, tmp);
		if (bytes < BUFFER_SIZE)
			read_again = 0;
	}
	free(tmp);
	tmp = NULL;
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	line = NULL;
	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = gn_read_to_buf(buf, fd);
	if (!buf)
		return (NULL);
	if (buf[0] == '\0')
	{
		gn_free_buf(&buf);
		return (NULL);
	}
	line = gn_extract_line(buf);
	buf = gn_realloc_buf(buf);
	return (line);
}
