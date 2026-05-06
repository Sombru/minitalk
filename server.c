#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void handle_usr_sig(int sig)
{
	ft_printf("recieved signal: %d\n", sig);
}

int main()
{
	struct sigaction sa = {0};
	sa.sa_handler = handle_usr_sig;
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("pid: %d\n", getpid());
	while (1)
	{

		
	}
	
}