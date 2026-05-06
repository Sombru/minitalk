#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

// ◦ write
// ◦ ft_printf or any equivalent YOU coded
// ◦ signal
// ◦ sigemptyset
// ◦ sigaddset
// ◦ sigaction
// ◦ kill
// ◦ getpid
// ◦ malloc
// ◦ free
// ◦ pause
// ◦ sleep
// ◦ usleep
// ◦ exit

// struct sigaction {
//    void     (*sa_handler)(int);
//    void     (*sa_sigaction)(int, siginfo_t *, void *);
//    sigset_t   sa_mask;
//    int        sa_flags;
//    void     (*sa_restorer)(void);
// };

int main(int argc, char** argv)
{
	if (argc != 3)
		return ft_printf("Error: bad number of arguments\n");
	kill(ft_atoi(argv[1]), SIGUSR1);
	printf("%s\n", argv[2]);
	
	
}