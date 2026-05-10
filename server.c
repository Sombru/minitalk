#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void handle_usr_sig1(int sig)
{
	(void)sig;
	ft_printf("1\n");
}

void handle_usr_sig2(int sig)
{
	(void)sig;
	ft_printf("0\n");
}


int main()
{
	struct sigaction sa1;
	struct sigaction sa2;
	sa1.sa_handler = handle_usr_sig1;
	sa2.sa_handler = handle_usr_sig2;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL); 
	ft_printf("pid: %d\n", getpid());
	while (1)
	{

		
	}
	
}