/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:20:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/08 20:44:33 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);
char			*gn_extract_line(char *buf);
char			*gn_realloc_buf(char *buf);

unsigned int	gn_strlen(char *str);
int				gn_find_newline(char *str);
char			*gn_join_buf(char *buf, char *tmp);
void			gn_free_buf(char **buf);
char			*gn_create_buf(char *buf);

#endif