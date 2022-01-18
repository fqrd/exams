#include "get_next_line.h"

int main(void)
{
	char *line = NULL;
	int i = 1;

	while ((i = get_next_line(&line)) == 1)
	{
		printf("%s\n", line);
		
		free(line);
	}
	if (i == 0)
	{
		printf("%s",line);
		free(line);
	}
	return (0);
}

