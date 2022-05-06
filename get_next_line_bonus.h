/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:10:54 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/06 13:18:54 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	The limit of the total BUFFER_SIZE is 2147483647 (SIZE_MAX).
	In read() man page the function is defined with SSIZE_MAX 
	  --> limit depends on the OS. E.g. on mac it would be 64-bit-architecture
	  with SIZE_MAX of 4294967295.
	In my case the func. gn_read_to_buf() allocates memory of BUFFER_SIZE + 1
	--> the max. allocatable heap memory is (SIZE_MAX / 2) --> 2147483647
*/
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif

char	*get_next_line(int fd);
size_t	gn_strlen(char *s);
int		gn_find_nl(char *str);
char	*gn_strjoin(char *buf, char *tmp);
char	*gn_read_to_buf(int fd, char *buf);
char	*gn_extract_line(char *buf);
char	*gn_calc_rest(char *buf);
char	*gn_set_buf(char *buf);
void	gn_free_buf(char **buf);

#endif
