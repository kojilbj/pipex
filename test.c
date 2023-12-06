#include <stdio.h>
#include <unistd.h>

int	main(int ac, char *av[], char *env[])
{
	printf("access = %i", access("/bin/cat", X_OK));
	return 0;
}
