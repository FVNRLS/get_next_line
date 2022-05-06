/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:25:56 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/06 12:59:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	returns the length of string s without null term
*/
size_t	gn_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*	Searches for the first occurrence of the character c in the string pointed 
	to by the argument str. 
	Returns a pointer to the first occurrence of the character c in the string 
	str, or NULL if the character was not found.
*/
int	gn_find_nl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
/*
	Concatenates current buf and the read result (tmp) into a new buf (join)
	Frees the old and returns a new buf (join).
*/

void	gn_free_buf(char **buf)
{
	free(*buf);
	*buf = NULL;
}

char	*gn_set_buf(char *buf)
{
	buf = malloc(sizeof(char) * 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	return (buf);
}

char	*gn_strjoin(char *buf, char *tmp)
{
	int		i;
	int		j;
	char	*join;

	if (!buf)
		buf = gn_set_buf(buf);
	join = malloc(sizeof(char) * ((gn_strlen(buf) + gn_strlen(tmp)) + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (buf[i] != '\0')
	{
		join[i] = buf[i];
		i++;
	}
	j = 0;
	while (tmp[j] != '\0')
		join[i++] = tmp[j++];
	join[i] = '\0';
	gn_free_buf(&buf);
	return (join);
}
