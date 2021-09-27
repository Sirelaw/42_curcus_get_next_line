
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	FILE	*fptr;
	int		i = 0;
	int		fd;
	char	*s = "";

	fptr = fopen("testfile.txt", "r");
	if(fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	fd = fileno(fptr);

	while(s)
	{
		s = get_next_line(fd);
		printf("%s", s);
		i++;
	}
	//system("leaks a.out");
	return (0);
}