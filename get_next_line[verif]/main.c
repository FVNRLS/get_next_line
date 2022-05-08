#include "get_next_line.h"

#include <stdio.h>
int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		i;
	char	*line;
		
	fd1 = open("/home/amenra/VisualStudioProjects/get_next_line/tests/lorem_ipsum.txt", O_RDONLY);
	fd2 = open("/home/amenra/VisualStudioProjects/get_next_line/tests/empty_line.txt", O_RDONLY);
	fd3 = open("/home/amenra/VisualStudioProjects/get_next_line/tests/empty_file.txt", O_RDONLY);
	fd4 = open("/home/amenra/VisualStudioProjects/get_next_line/tests/big_line_no_nl.txt", O_RDONLY);

	printf("\n\n***********************************************\n");
	line = NULL;
	i = 0;
	while (i < 10)
	{
		line = get_next_line(fd1);
		if (line == NULL)
		{
			printf("%s", line);
			printf("\n");
		}
		else
			printf("%s", line);
		i++;
		free(line);
		line = NULL;
	}
	close(fd1);
	

	printf("\n\n***********************************************\n");
	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd2);
		if (line == NULL)
		{
			printf("%s", line);
			printf("\n");
		}
		else
			printf("%s", line);		
		i++;
		free(line);
		line = NULL;
	}
	close(fd2);

	
	printf("\n\n***********************************************\n");
	i = 0;
	while (i < 3)
	{
		line = get_next_line(fd3);
		if (line == NULL)
		{
			printf("%s", line);
			printf("\n");
		}
		else
			printf("%s", line);		
		i++;
		free(line);
		line = NULL;
	}
	close(fd3);


	printf("\n\n***********************************************\n");
	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd4);
		if (line == NULL)
		{
			printf("%s", line);
			printf("\n");
		}
		else
			printf("%s", line);		
		i++;
		free(line);
		line = NULL;
	}
	close(fd4);
		
	return (0);
}