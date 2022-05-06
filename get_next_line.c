/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:20:36 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/06 12:57:21 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
 	Approach:
	At start check for invalid fd, BUFFER_SIZE or if fd is closed.
 	Read everything into a static buffer until \n was found in the read result.
	(Return NULL if the read result is 0)
	Then split the static buf into 2 strings:
		extract (until \n or \0) and return the line, including \n and \0
			--> malloc depends on situation, whether \n was found or not
			--> if \n was found, then allocate 2 bytes more (for \n and \0)
		realloc the static buffer to store the rest (without extracted line)
		join the next read result to it!
 */
char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	line = NULL;
	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = gn_read_to_buf(fd, buf);
	if (!buf)
		return (NULL);
	if (buf[0] == '\0')
	{
		gn_free_buf(&buf);
		return (NULL);
	}
	line = gn_extract_line(buf);
	buf = gn_calc_rest(buf);
	return (line);
}

/*
	Read from fd to tmp[] array, then join the read result to the static buf
	Check the buf every time before reading for \n
		--> stop reading if \n was found
		--> stop reading if number of read bytes < BUFFER_SIZE (EOF is reached)
*/
char	*gn_read_to_buf(int fd, char *buf)
{
	char	*tmp;
	int		bytes;
	int		read_again;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	bytes = 0;
	read_again = 1;
	while (read_again == 1)
	{
		if (gn_find_nl(buf) == 1)
			break ;
		bytes = read(fd, &tmp[0], BUFFER_SIZE);
		tmp[bytes] = '\0';
		buf = gn_strjoin(buf, tmp);
		if (bytes < BUFFER_SIZE)
			read_again = 0;
	}
	free(tmp);
	tmp = NULL;
	return (buf);
}

/*
	Go through the buf and search for \n or \0
	Depending on the search result - allocate the needed amount of memory
	Then copy the content from buf until the \n or \0 into a new line
	Return the new line
*/
char	*gn_extract_line(char *buf)
{
	char	*line;
	int		i;

	line = NULL;
	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else if (buf[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
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

/*
	Calculate the rest of the buf, which wasn't extracted into the line:
	Reallocate memory starting from the first occurence of \n until \0
	Copy the sequence from buf into the new memory storage (rest)
	Free the old buf and return the new.
*/
char	*gn_calc_rest(char *buf)
{
	char	*rest;
	int		i;
	int		j;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		gn_free_buf(&buf);
		return (NULL);
	}
	rest = malloc(sizeof(char) * ((gn_strlen(buf) - i) + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (buf[i] != '\0')
		rest[j++] = buf[i++];
	rest[j] = '\0';
	gn_free_buf(&buf);
	return (rest);
}
