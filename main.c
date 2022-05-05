/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:15:40 by rmazurit          #+#    #+#             */
/*   Updated: 2022/05/05 14:50:52 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int	main(void)
{

/*********************************** MANDATORY TEST *****************************************/
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;
	fd1 = open("./tests/lorem_ipsum.txt", O_RDONLY);
	fd2 = open("./tests/empty_line.txt", O_RDONLY);
	fd3 = open("./tests/empty_file.txt", O_RDONLY);
	fd4 = open("./tests/42_with_nl.txt", O_RDONLY);
	fd5 = open("./tests/nl.txt", O_RDONLY);
	fd6 = open("./tests/big_line_no_nl.txt", O_RDONLY);
	
	printf("\n\n******* MANDATORY TEST *******");
	i = 1;	
	printf("\n\n******* BIG TEXT *******\n");
	while (i < 10)
	{	
		line = get_next_line(fd1);
		printf("line [%d]: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd1);
	i = 1;
	printf("\n\n******* EMPTY LINE CHECK *******\n");
	while (i < 6)
	{	
		line = get_next_line(fd2);
		printf("line [%d]: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd2);
	i = 1;
	printf("\n\n******* EMPTY FILE *******\n");
	while (i < 4)
	{
		line = get_next_line(fd3);
		printf("line [%d]: %s\n", i, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd3);
	i = 1;
	printf("\n\n******* 42 WITH NL (no newline at the end) *******\n");
	while (i < 3)
	{
		line = get_next_line(fd4);
		printf("line [%d]: %s", i, line);
		line = NULL;
		i++;
	}
	close(fd4);

	i = 1;
	printf("\n\n******* EMPTY FILE WITH NEWLINE *******\n");
	while (i < 3)
	{
		line = get_next_line(fd5);
		printf("line [%d]: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd5);

	i = 1;
	printf("\n\n******* BIG LINE NO NEWLINE *******\n");
	while (i < 2)
	{
		line = get_next_line(fd6);
		printf("line [%d]: %s", i, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd6);
	
/*********************************** BONUS TEST *****************************************/
	printf("\n\n\n******* BONUS TEST *******\n");

	fd1 = open("./tests/lorem_ipsum.txt", O_RDONLY);
	fd2 = open("./tests/empty_line.txt", O_RDONLY);
	fd3 = open("./tests/empty_file.txt", O_RDONLY);

	printf("\n******* FIRST CALL of 3 fd's *******\n");
	line = get_next_line(fd1);
	printf("line [1]: %s", line);
	free(line);
	line = NULL;
	line = get_next_line(fd2);
	printf("line [1]: %s", line);
	free(line);
	line = NULL;
	line = get_next_line(fd3);
	printf("line [1]: %s", line);
	free(line);
	line = NULL;
	printf("\n******* SECOND CALL of 3 fd's *******\n");
	line = get_next_line(fd1);
	printf("line [2]: %s", line);
	free(line);
	line = NULL;
	line = get_next_line(fd2);
	printf("line [2]: %s", line);
	free(line);
	line = NULL;
	line = get_next_line(fd3);
	printf("line [2]: %s", line);
	free(line);
	close(fd1);
	printf("\n******* THIRD CALL of 3 fd's (FD 1 is CLOSED!) *******\n");
	line = get_next_line(fd1);
	printf("line [3]: %s\n", line);
	free(line);
	line = NULL;
	line = get_next_line(fd2);
	printf("line [3]: %s", line);
	free(line);
	line = NULL;
	line = get_next_line(fd3);
	printf("line [3]: %s", line);
	free(line);

	close(fd2);
	close(fd3);
	
	return (0);
	
	//for testing purposes:
	/* write output of test 4 to a separate file:
	int fd = open("test_gnl", O_RDWR | O_CREAT, 0777);
	dup2(fd, STDOUT_FILENO); */
}
