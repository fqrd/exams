#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc < 3)
		return (0);

	char		*str	= argv[1];
	int		d	= atoi(argv[2]);
	unsigned int	x	= atoi(argv[3]);

	ft_printf("Hello %s\n", str);
	printf("Hello %s\n", str);

	ft_printf("Number %d\n", d);
	printf("Number %d\n", d);

	ft_printf("%x\n", x);
	printf("%x\n.\n", x);
		
	return (0);
}
