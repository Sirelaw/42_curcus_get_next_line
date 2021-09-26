
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	FILE	*fptr;
	int		i = 0;
	int		fd;

	fptr = fopen("testfile.txt", "r");
	if(fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	fd = fileno(fptr);

	while(i < 3)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);
}
