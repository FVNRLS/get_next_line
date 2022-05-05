/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:25:56 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/05 13:58:55 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
	returns the length of string s without null term
*/
size_t	gn_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
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

char	*gn_strjoin(char *buf, char *tmp)
{
	int		i;
	int		j;
	char	*join;

	if (!buf)
	{
		buf = (char *)malloc(1 * sizeof(char));
		buf[0] = '\0';
	}
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
	free(buf);
	return (join);
}
