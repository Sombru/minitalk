#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	// ft_printf("pid: %d\n", getpid());
	ft_putstr_fd("Hello\n", STDOUT_FILENO);
	while (1)
	{
		
	}
	
}