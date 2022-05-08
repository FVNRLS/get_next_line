/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:26:43 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/08 20:43:49 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gn_create_buf(char *buf)
{
	buf = malloc(sizeof(char));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	return (buf);
}

void	gn_free_buf(char **buf)
{
	free(*buf);
	*buf = NULL;
}

unsigned int	gn_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	gn_find_newline(char *str)
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

char	*gn_join_buf(char *buf, char *tmp)
{
	char	*join;
	int		i;
	int		j;

	if (!tmp)
		return (NULL);
	join = malloc(sizeof(char) * (gn_strlen(buf) + gn_strlen(tmp) + 1));
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
	{
		join[i] = tmp[j];
		i++;
		j++;
	}
	join[i] = '\0';
	gn_free_buf(&buf);
	return (join);
}
