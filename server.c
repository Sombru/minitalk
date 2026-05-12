#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char message[10000];

void handle_usr_sig1(int sig)
{
	(void)sig;
	ft_printf("1\n");
	message[0] |= 1; // insert bit
}

void handle_usr_sig2(int sig)
{
	(void)sig;
	ft_printf("0\n");
	message[0] >>= 1; // shift bits to left
}


int main()
{
	struct sigaction sa1;
	struct sigaction sa2;
	sa1.sa_handler = &handle_usr_sig1;
	sa2.sa_handler = &handle_usr_sig2;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL); 
	ft_printf("pid: %d\n", getpid());
	while (1)
	{
		ft_printf("char: %c\n", message[0]);
		ft_printf("value: %i\n", message[0]);
		pause();
		
	}
	
}